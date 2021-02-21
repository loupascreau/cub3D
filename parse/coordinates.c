/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:23:18 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/19 14:35:05 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_set_direction(t_parse *parse, char c)
{
	if (c == 'N')
	{
		parse->dirx = 0;
		parse->diry = -1;
		parse->planex = 0.66;
	}
	if (c == 'W')
	{
		parse->dirx = -1;
		parse->diry = 0;
		parse->planey = -0.66;
	}
	if (c == 'S')
	{
		parse->dirx = 0;
		parse->diry = 1;
		parse->planex = -0.66;
	}
	if (c == 'E')
	{
		parse->dirx = 1;
		parse->diry = 0;
		parse->planey = 0.66;
	}
}

int		ft_find_player(t_parse *parse)
{
	int	i;
	int	j;

	j = 0;
	while (parse->tab[j])
	{
		i = 0;
		while (parse->tab[j][i])
		{
			if (parse->tab[j][i] == 'N' || parse->tab[j][i] == 'S'
			|| parse->tab[j][i] == 'E' || parse->tab[j][i] == 'W')
			{
				parse->posx = i;
				parse->posy = j;
				ft_set_direction(parse, parse->tab[j][i]);
				parse->tab[j][i] = '0';
				return (1);
			}
			i++;
		}
		j++;
	}
	return (ft_error(3));
}
