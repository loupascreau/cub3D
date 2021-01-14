/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:30:19 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/14 14:18:14 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str, parse_t *parse)
{
	int	i;
	int sign;
	int result;

	i = parse->i;
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
	parse->i = i;
	return (result * sign);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;
	unsigned int	size;

	i = 0;
//	printf("start = %d, len = %d, s = %s\n", (int)start, (int)len, s);
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
