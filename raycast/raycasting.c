/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:29:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/27 16:06:24 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_rayon(t_cast *cast)
{
	if (cast->ray_dirx < 0)
	{
		cast->stepx = -1;
		cast->side_distx = (cast->posx - cast->mapx) * cast->delta_distx;
	}
	else
	{
		cast->stepx = 1;
		cast->side_distx = (cast->mapx + 1.0 - cast->posx) * cast->delta_distx;
	}
	if (cast->ray_diry < 0)
	{
		cast->stepy = -1;
		cast->side_disty = (cast->posy - cast->mapy) * cast->delta_disty;
	}
	else
	{
		cast->stepy = 1;
		cast->side_disty = (cast->mapy + 1.0 - cast->posy) * cast->delta_disty;
	}
}

void	ft_dda(t_cast *cast)
{
	cast->hit = 0;
	while (cast->hit == 0)
	{
		if (cast->side_distx < cast->side_disty)
		{
			cast->side_distx += cast->delta_distx;
			cast->mapx += cast->stepx;
			cast->side = 0;
		}
		else
		{
			cast->side_disty += cast->delta_disty;
			cast->mapy += cast->stepy;
			cast->side = 1;
		}
		if (cast->map[cast->mapy][cast->mapx] == 1)
			cast->hit = 1;
	}
	if (cast->side == 0)
		cast->perp_wall_dist = (cast->mapx - cast->posx + (1 - cast->stepx) / 2)
		/ cast->ray_dirx;
	else
		cast->perp_wall_dist = (cast->mapy - cast->posy + (1 - cast->stepy) / 2)
		/ cast->ray_diry;
	cast->buffer[cast->x] = cast->perp_wall_dist;
}

int		ft_raycasting(t_cast *cast)
{
	if (!(cast->buffer = (double *)malloc(sizeof(double) * cast->screen_width)))
		return (ft_error(4));
	cast->x = 0;
	while (cast->x < cast->screen_width)
	{
		cast->camerax = 2 * cast->x / (double)cast->screen_width - 1;
		cast->ray_dirx = cast->dirx + cast->planex * cast->camerax;
		cast->ray_diry = cast->diry + cast->planey * cast->camerax;
		cast->mapx = cast->posx;
		cast->mapy = cast->posy;
		cast->delta_distx = fabs(1 / cast->ray_dirx);
		cast->delta_disty = fabs(1 / cast->ray_diry);
		ft_rayon(cast);
		ft_dda(cast);
		ft_textures(cast);
		cast->x++;
	}
	return (1);
}
