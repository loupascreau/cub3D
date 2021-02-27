/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:00:42 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/27 19:34:27 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_recup_sprites(t_parse *parse, t_cast *cast)
{
	int	i;
	int	j;
	int	n;

	j = 0;
	n = 0;
	while (j < parse->height)
	{
		i = 0;
		while (parse->tab[j][i])
		{
			if (parse->tab[j][i] == '2' && n < 100)
			{
				cast->sprite[n].x = i + 0.5;
				cast->sprite[n].y = j + 0.5;
				n++;
			}
			i++;
		}
		j++;
	}
	return (n);
}

void	ft_sort_sprite(int *sprite_order, double *sprite_dist, int nbr_sprite)
{
	int		i;
	double	tmp_dist;
	int		tmp_order;

	i = 0;
	while (i < nbr_sprite - 1)
	{
		if (sprite_dist[i] < sprite_dist[i + 1])
		{
			tmp_dist = sprite_dist[i];
			sprite_dist[i] = sprite_dist[i + 1];
			sprite_dist[i + 1] = tmp_dist;
			tmp_order = sprite_order[i];
			sprite_order[i] = sprite_order[i + 1];
			sprite_order[i + 1] = tmp_order;
			i = -1;
		}
		i++;
	}
}

void	ft_dist_sprite(t_cast *cast, int *sprite_order, double *sprite_dist)
{
	int i;

	i = 0;
	while (i < cast->nbr_sprite)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((cast->posx - cast->sprite[i].x) *
		(cast->posx - cast->sprite[i].x)
		+ (cast->posy - cast->sprite[i].y) * (cast->posy - cast->sprite[i].y));
		i++;
	}
	ft_sort_sprite(sprite_order, sprite_dist, cast->nbr_sprite);
}

void	ft_raycast_sprite(t_cast *cast, int *sprite_order, int i)
{
	cast->spritex = cast->sprite[sprite_order[i]].x - cast->posx;
	cast->spritey = cast->sprite[sprite_order[i]].y - cast->posy;
	cast->inv_det = 1.0 / (cast->planex * cast->diry - cast->dirx *
	cast->planey);
	cast->transformx = cast->inv_det * (cast->diry * cast->spritex -
	cast->dirx * cast->spritey);
	cast->transformy = cast->inv_det * (-cast->planey * cast->spritex +
	cast->planex * cast->spritey);
	cast->sprite_screenx = (int)((cast->screen_width / 2) * (1 +
	cast->transformx / cast->transformy));
	cast->sprite_height = abs((int)(cast->screen_height / cast->transformy));
	cast->draw_starty = -cast->sprite_height / 2 + cast->screen_height / 2;
	if (cast->draw_starty < 0)
		cast->draw_starty = 0;
	cast->draw_endy = cast->sprite_height / 2 + cast->screen_height / 2;
	if (cast->draw_endy >= cast->screen_height)
		cast->draw_endy = cast->screen_height - 1;
	cast->sprite_width = abs((int)(cast->screen_height / cast->transformy));
	cast->draw_startx = -cast->sprite_width / 2 + cast->sprite_screenx;
	if (cast->draw_startx < 0)
		cast->draw_startx = 0;
	cast->draw_endx = cast->sprite_width / 2 + cast->sprite_screenx;
	if (cast->draw_endx >= cast->screen_width)
		cast->draw_endx = cast->screen_width - 1;
}

void	ft_sprite(t_cast *cast)
{
	int		i;
	int		y;
	int		d;
	int		sprite_order[cast->nbr_sprite];
	double	sprite_dist[cast->nbr_sprite];

	ft_dist_sprite(cast, sprite_order, sprite_dist);
	i = 0;
	d = 0;
	y = 0;
	while (i < cast->nbr_sprite)
	{
		ft_raycast_sprite(cast, sprite_order, i);
		cast->stripe = cast->draw_startx;
		while (cast->stripe < cast->draw_endx)
		{
			ft_draw_sprite(cast, d, y);
			cast->stripe++;
		}
		i++;
	}
}
