/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:23:18 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/27 14:21:20 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_set_direction(parse_t *parse, char c)
{
	if (c == 'N')
	{
		parse->dirX = 0;
		parse->dirY = -1;
	}
	if (c == 'W')
	{
		parse->dirX = -1;
		parse->dirY = 0;
	}
	if (c == 'S')
	{
		parse->dirX = 0;
		parse->dirY = 1;
	}
	if (c == 'E')
	{
		parse->dirX = 1;
		parse->dirY = 0;
	}
}

int		ft_find_player(parse_t *parse)
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
				parse->posX = i;
				parse->posY = j;
				ft_set_direction(parse, parse->tab[j][i]);
				parse->tab[j][i] = '0';
				return (1);
			}
			i++;
		}
		j++;
	}
	printf("Error\nYour map is missing starter coordinates");
	printf(" or she's not at end\n");
	return (0);
}
