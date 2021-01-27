/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:42:09 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/27 11:22:59 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_check_map_closed(char **tab, int i, int j)
{
	if (tab[j][i + 1] == '\0' || tab[j][i + 1] == ' '
	|| tab[j][i - 1] == ' ')
		return (0);
	if (tab[j - 1][i] == '\0' || tab[j - 1][i] == ' ')
		return (0);
	if (tab[j + 1] && (tab[j + 1][i] == '\0'
	|| tab[j - 1][i] == ' '))
		return (0);
	return (1);
}

int		ft_check_map(char **tab)
{
	int	j;
	int	i;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (i == 0 && tab[j][i] == '0')
				return (0);
			if (tab[j][i] != '1' && tab[j][i] != ' ')
			{
				if (ft_check_map_closed(tab, i, j) == 0)
					return (0);
			}
			if (j > 0 && tab[j][i] == ' ' && tab[j - 1][i] == '0')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
