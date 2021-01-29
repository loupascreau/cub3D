/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:22:44 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/29 10:41:46 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft.h"

int		ft_pos_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *nbr, char *base)
{
	int i;
	int	result;
	int	sign;
	int size_base;

	i = 0;
	result = 0;
	sign = 1;
	size_base = ft_strlen(base);
	while ((nbr[i] < 14 && nbr[i] > 8) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nbr[i] && ft_pos_base(nbr[i], base) >= 0)
	{
		result = result * size_base + ft_pos_base(nbr[i], base);
		i++;
	}
	return (result * sign);
}

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' ||
		(base[i] < 14 && base[i] > 8))
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}
