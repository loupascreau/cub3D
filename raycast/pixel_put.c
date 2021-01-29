/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:48:05 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/29 14:51:04 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_pixel_put(cast_t *cast)
{
	ft_raycasting(cast);
	mlx_put_image_to_window(cast->mlx, cast->win, cast->img, 0, 0);
	return (0);
}

int		ft_key_hook(int key, cast_t *cast)
{
	if (key == 119)
	{
		if (cast->map[(int)cast->posY][(int)(cast->posX + cast->dirX)] == 0)
			cast->posX += cast->dirX;
		if (cast->map[(int)(cast->posY + cast->dirY)][(int)cast->posX] == 0)
			cast->posY += cast->dirY;
	}
	if (key == 115)
	{
		if (cast->map[(int)cast->posY][(int)(cast->posX - cast->dirX)] == 0)
			cast->posX -= cast->dirX;
		if (cast->map[(int)(cast->posY - cast->dirY)][(int)cast->posX] == 0)
			cast->posY -= cast->dirY;
	}
	if (key == 97)
	{
		cast->old_dirX = cast->dirX;
		cast->dirX = (cast->dirX * cos(5 * (cast->pi / 180))) - (cast->dirY * sin(5 * (cast->pi / 180)));
		cast->dirY = (cast->old_dirX * sin(5 * (cast->pi / 180))) + (cast->dirY * cos(5 * (cast->pi / 180)));
		cast->old_planeX = cast->planeX;
		cast->planeX = (cast->planeX * cos(5 * (cast->pi / 180))) - (cast->planeY * sin(5 * (cast->pi / 180)));
		cast->planeY = (cast->old_planeX * sin(5 * (cast->pi / 180))) + (cast->planeY * cos(5 * (cast->pi / 180)));
	}
	if (key == 100)
	{
		cast->old_dirX = cast->dirX;
		cast->dirX = (cast->dirX * cos(-(5 * (cast->pi / 180)))) - (cast->dirY * sin(-(5 * (cast->pi / 180))));
		cast->dirY = (cast->old_dirX * sin(-(5 * (cast->pi / 180)))) + (cast->dirY * cos(-(5 * (cast->pi / 180))));
		cast->old_planeX = cast->planeX;
		cast->planeX = (cast->planeX * cos(-(5 * (cast->pi / 180)))) - (cast->planeY * sin(-(5 * (cast->pi / 180))));
		cast->planeY = (cast->old_planeX * sin(-(5 * (cast->pi / 180)))) + (cast->planeY * cos(-(5 * (cast->pi / 180))));
	}
	return (0);
}

void	my_mlx_pixel_put(cast_t *cast, int x, int draw_start, int draw_end, int color)
{
	char	*dst;
	int		i;

	i = 0;
	while (i < draw_start)
	{
		dst = &cast->addr[(i * cast->size_line) + (x * (cast->bits_per_pixels / 8))];
		*(unsigned int*)dst = cast->ceil;
		i++;
	}
	while (draw_start < draw_end)
	{
		dst = &cast->addr[(draw_start * cast->size_line) + (x * (cast->bits_per_pixels / 8))];
		*(unsigned int*)dst = color;
		draw_start++;
	}
	while (draw_start < cast->screen_height && (draw_start != 0))
	{
		dst = &cast->addr[(draw_start * cast->size_line) + (x * (cast->bits_per_pixels / 8))];
		*(unsigned int*)dst = cast->floor;
		draw_start++;
	}
}
