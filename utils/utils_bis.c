/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:01:17 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/06 14:57:59 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_free(char *line, char **tmp)
{
	free(line);
	line = NULL;
	free(tmp);
	tmp = NULL;
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*tab;

	tab = (void *)s;
	i = 0;
	while (i < n)
	{
		tab[i] = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*cpy;
	unsigned int		i;

	i = 0;
	dst = (unsigned char *)dest;
	cpy = (unsigned char *)src;
	if (dst == NULL && cpy == NULL)
		return (NULL);
	while (i < n)
	{
		dst[i] = cpy[i];
		i++;
	}			
	return (dest);
}
