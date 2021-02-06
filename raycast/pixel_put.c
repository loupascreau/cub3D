/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:48:05 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/06 15:01:49 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_expose(cast_t *cast)
{
	int	i;

	i = 0;
	cast->img = mlx_new_image(cast->mlx, cast->screen_width, cast->screen_height);
	cast->addr = mlx_get_data_addr(cast->img, &cast->bits_per_pixels, &cast->size_line, &cast->endian);
	while (i < cast->screen_width * (cast->screen_height / 2))
		*(int *)&cast->addr[i++ * (cast->bits_per_pixels / 8)] = cast->ceil;
	while (i < cast->screen_width * cast->screen_height)
		*(int *)&cast->addr[i++ * (cast->bits_per_pixels / 8)] = cast->floor;
	if (ft_raycasting(cast) == 0)
		return (0);
	mlx_put_image_to_window(cast->mlx, cast->win, cast->img, 0, 0);
	return (1);
}

int		ft_close_window(cast_t *cast)
{
	mlx_loop_end(cast->mlx);
	mlx_destroy_image(cast->mlx, cast->img);
	mlx_destroy_window(cast->mlx, cast->win);
	mlx_destroy_display(cast->mlx);
	free(cast->mlx);
	exit(0);
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
	if (key == 100)
	{
		if (cast->map[(int)(cast->posY + cast->planeY)][(int)cast->posX] == 0)
			cast->posY += cast->planeY;
		if (cast->map[(int)cast->posY][(int)(cast->posX + cast->planeX)] == 0)
			cast->posX += cast->planeX;
	}
	if (key == 97)
	{
		if (cast->map[(int)(cast->posY - cast->planeY)][(int)cast->posX] == 0)
			cast->posY -= cast->planeY;
		if (cast->map[(int)cast->posY][(int)(cast->posX - cast->planeX)] == 0)
			cast->posX -= cast->planeX;
	}
	if (key == 65361)
	{
		cast->old_dirX = cast->dirX;
		cast->dirX = (cast->dirX * cos(5 * (cast->pi / 180))) - (cast->dirY * sin(5 * (cast->pi / 180)));
		cast->dirY = (cast->old_dirX * sin(5 * (cast->pi / 180))) + (cast->dirY * cos(5 * (cast->pi / 180)));
		cast->old_planeX = cast->planeX;
		cast->planeX = (cast->planeX * cos(5 * (cast->pi / 180))) - (cast->planeY * sin(5 * (cast->pi / 180)));
		cast->planeY = (cast->old_planeX * sin(5 * (cast->pi / 180))) + (cast->planeY * cos(5 * (cast->pi / 180)));
	}
	if (key == 65363)
	{
		cast->old_dirX = cast->dirX;
		cast->dirX = (cast->dirX * cos(-(5 * (cast->pi / 180)))) - (cast->dirY * sin(-(5 * (cast->pi / 180))));
		cast->dirY = (cast->old_dirX * sin(-(5 * (cast->pi / 180)))) + (cast->dirY * cos(-(5 * (cast->pi / 180))));
		cast->old_planeX = cast->planeX;
		cast->planeX = (cast->planeX * cos(-(5 * (cast->pi / 180)))) - (cast->planeY * sin(-(5 * (cast->pi / 180))));
		cast->planeY = (cast->old_planeX * sin(-(5 * (cast->pi / 180)))) + (cast->planeY * cos(-(5 * (cast->pi / 180))));
	}
	if (key == 65307)
	{
		mlx_loop_end(cast->mlx);
		mlx_destroy_image(cast->mlx, cast->img);
		mlx_destroy_window(cast->mlx, cast->win);
		mlx_destroy_display(cast->mlx);
		free(cast->mlx);
		exit(0);
	}
	return (0);
}

/*void	my_mlx_pixel_put(cast_t *cast, int x, int draw_start, int draw_end, int color)
{
	char	*dst;
	int		i;

	i = 0;
	(void)draw_end;
	(void)color;
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
}*/
