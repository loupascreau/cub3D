/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:29:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/01 12:29:23 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_raycasting(cast_t *cast)
{
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
		cast->hit = 0;
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
		cast->line_height = (int)(cast->screen_height / cast->perp_wall_dist);
		cast->draw_start = (-cast->line_height) / 2 + cast->screen_height / 2;
		if (cast->draw_start < 0)
			cast->draw_start = 0;
		cast->draw_end = cast->line_height / 2 + cast->screen_height / 2;
		if (cast->draw_end >= cast->screen_height)
			cast->draw_end = cast->screen_height - 1;
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
		my_mlx_pixel_put(cast, cast->x, cast->draw_start, cast->draw_end, cast->color);
		cast->x++;
	}
}
