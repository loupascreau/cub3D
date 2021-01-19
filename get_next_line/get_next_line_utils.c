/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:17:24 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/18 09:25:22 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_strdup(char *s)
{
	char	*new;
	int		size;
	int		i;

	size = ft_strlen(s);
	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		new[j] = s2[i++];
		j++;
	}
	new[j] = '\0';
	free(s1);
	return (new);
}
