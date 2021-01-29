/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:21:48 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/29 10:58:47 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft.h"

char	*ft_putnbr_in_base(int nbr, char *base, char *final, int i)
{
	if (nbr < 0)
	{
		final[0] = '-';
		nbr = -nbr;
	}
	if (nbr < ft_strlen(base))
	{
		final[i] = base[nbr];
	}
	else
	{
		ft_putnbr_in_base(nbr / ft_strlen(base), base, final, i - 1);
		final[i] = base[nbr % ft_strlen(base)];
	}
	return (final);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal;
	int		size_base_to;
	int		nbr_to_malloc;
	int		tmp;
	char	*final;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	decimal = ft_atoi_base(nbr, base_from);
	if (decimal == 0)
		nbr_to_malloc = 1;
	else
		nbr_to_malloc = 0;
	tmp = decimal;
	size_base_to = ft_strlen(base_to);
	while (tmp != 0)
	{
		tmp = tmp / size_base_to;
		nbr_to_malloc++;
	}
	decimal < 0 ? nbr_to_malloc++ : nbr_to_malloc;
	final = (char *)malloc(sizeof(char) * (nbr_to_malloc + 1));
	final = ft_putnbr_in_base(decimal, base_to, final, nbr_to_malloc - 1);
	final[nbr_to_malloc] = '\0';
	free(nbr);
	return (final);
}
