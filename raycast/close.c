/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:45:28 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/10 15:49:08 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_close_window(cast_t *cast)
{
	ft_free_map(cast);
	mlx_loop_end(cast->mlx);
	mlx_destroy_image(cast->mlx, cast->img);
	mlx_destroy_image(cast->mlx, cast->img);
	mlx_destroy_image(cast->mlx, cast->tex[0].img);
	mlx_destroy_image(cast->mlx, cast->tex[1].img);
	mlx_destroy_image(cast->mlx, cast->tex[2].img);
	mlx_destroy_image(cast->mlx, cast->tex[3].img);
	mlx_destroy_image(cast->mlx, cast->tex[4].img);
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
		ft_free_map(cast);
		mlx_loop_end(cast->mlx);
		mlx_destroy_image(cast->mlx, cast->img);
		mlx_destroy_image(cast->mlx, cast->tex[0].img);
		mlx_destroy_image(cast->mlx, cast->tex[1].img);
		mlx_destroy_image(cast->mlx, cast->tex[2].img);
		mlx_destroy_image(cast->mlx, cast->tex[3].img);
		mlx_destroy_image(cast->mlx, cast->tex[4].img);
		mlx_destroy_window(cast->mlx, cast->win);
		mlx_destroy_display(cast->mlx);
		free(cast->mlx);
		exit(0);
	}
	return (0);
}
