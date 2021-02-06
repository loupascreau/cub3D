/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:29:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/06 15:20:16 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_raycasting(cast_t *cast)
{
	if (!(cast->buffer = (double *)malloc(sizeof(double) * cast->screen_width)))
		return (ft_error(4));
	cast->x = 0;
	while (cast->x < cast->screen_width)
	{
		cast->cameraX = 2 * cast->x / (double)cast->screen_width - 1;
		cast->ray_dirX = cast->dirX + cast->planeX * cast->cameraX;
		cast->ray_dirY = cast->dirY + cast->planeY * cast->cameraX;
		cast->mapX = cast->posX;
		cast->mapY = cast->posY;
		if (cast->ray_dirY == 0)
			cast->delta_distX = 0;
		else
			cast->delta_distX = fabs(1 / cast->ray_dirX);
		if (cast->ray_dirX == 0)
			cast->delta_distY = 0;
		else
			cast->delta_distY = fabs(1 / cast->ray_dirY);
			//
		if (cast->ray_dirX < 0)
		{
			cast->stepX = -1;
			cast->side_distX = (cast->posX - cast->mapX) * cast->delta_distX;
		}
		else
		{
			cast->stepX = 1;
			cast->side_distX = (cast->mapX + 1.0 - cast->posX) * cast->delta_distX;
		}
		if (cast->ray_dirY < 0)
		{
			cast->stepY = -1;
			cast->side_distY = (cast->posY - cast->mapY) * cast->delta_distY;
		}
		else
		{
			cast->stepY = 1;
			cast->side_distY = (cast->mapY + 1.0 - cast->posY) * cast->delta_distY;
		}
			//
		cast->hit = 0;
		while (cast->hit == 0)
		{
			if (cast->side_distX < cast->side_distY)
			{
				cast->side_distX += cast->delta_distX;
				cast->mapX += cast->stepX;
				cast->side = 0;
			}
			else
			{
				cast->side_distY += cast->delta_distY;
				cast->mapY += cast->stepY;
				cast->side = 1;
			}
			if (cast->map[cast->mapY][cast->mapX] > 0)
				cast->hit = 1;
		}
		if (cast->side == 0)
			cast->perp_wall_dist = (cast->mapX - cast->posX + (1 - cast->stepX) / 2) / cast->ray_dirX;
		else
			cast->perp_wall_dist = (cast->mapY - cast->posY + (1 - cast->stepY) / 2) / cast->ray_dirY;
		cast->buffer[cast->x] = cast->perp_wall_dist;
			//
		ft_textures(cast);
			//
		if (cast->side == 1)
		{
			if (cast->ray_dirY < 0)
				cast->color = 0xFF0000;
			else
				cast->color = 0x00FF00;
		}
		else
		{
			if (cast->ray_dirX < 0)
				cast->color = 0x0000FF;
			else
				cast->color = 0xFFFF00;
		}
//		my_mlx_pixel_put(cast, cast->x, cast->draw_start, cast->draw_end, cast->color);
		cast->x++;
	}
	return (1);
}
