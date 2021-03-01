/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:30:53 by lpascrea          #+#    #+#             */
/*   Updated: 2021/03/01 14:22:05 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_screen_size(t_parse *parse, t_cast *cast)
{
	if (parse->x > cast->sizex)
		cast->screen_width = cast->sizex;
	else
		cast->screen_width = parse->x;
	if (parse->y > cast->sizey)
		cast->screen_height = cast->sizey;
	else
		cast->screen_height = parse->y;
}

int		ft_set_params(t_parse *parse, t_cast *cast)
{
	cast->pi = 3.1415926535;
	cast->map_width = parse->longest;
	cast->map_height = parse->height;
	ft_screen_size(parse, cast);
	cast->dirx = parse->dirx;
	cast->diry = parse->diry;
	cast->posx = parse->posx + 0.5;
	cast->posy = parse->posy + 0.5;
	cast->planex = parse->planex;
	cast->planey = parse->planey;
	cast->floor = ft_atoi(parse->f);
	cast->ceil = ft_atoi(parse->c);
	free(parse->f);
	free(parse->c);
	cast->tex_width = 64;
	cast->tex_height = 64;
	close(parse->fd);
	return (1);
}

int		ft_setup_data_parse_cast(t_parse *parse, t_cast *cast)
{
	int	j;
	int i;

	j = 0;
	if (ft_set_params(parse, cast) == 0)
		return (0);
	if (!(cast->map = (int **)malloc(sizeof(int *) * cast->map_height + 1)))
		return (ft_error(4));
	while (j < parse->height)
	{
		i = 0;
		if (!(cast->map[j] = (int *)malloc(sizeof(int) * cast->map_width + 1)))
			return (ft_error(4));
		while (parse->tab[j][i])
		{
			cast->map[j][i] = parse->tab[j][i] - 48;
			i++;
		}
		free(parse->tab[j]);
		j++;
	}
	free(parse->tab);
	return (1);
}
