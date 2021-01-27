/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:30:19 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/27 11:20:37 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int	i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;
	unsigned int	size;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen((char *)s);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && (start + i) < size)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_putnbr_base(int nbr, char *tab, int i)
{
	static char base[] = "0123456789ABCDEF";

	if (nbr == 0)
	{
		tab[i] = '0';
		tab[i - 1] = '0';
		return (tab);
	}
	else if (nbr < 16)
		tab[i] = base[nbr];
	else
	{
		ft_putnbr_base(nbr / 16, tab, i - 1);
		tab[i] = base[nbr % 16];
	}
	return (tab);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
