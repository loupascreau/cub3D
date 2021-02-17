/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:45:28 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/17 15:53:55 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_close_window(t_cast *cast)
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
	return (0);
}

int		ft_key_hook(int key, t_cast *cast)
{
	if (key == 119)
	{
		if (cast->map[(int)cast->posy][(int)(cast->posx + cast->dirx)] == 0)
			cast->posx += cast->dirx;
		if (cast->map[(int)(cast->posy + cast->diry)][(int)cast->posx] == 0)
			cast->posy += cast->diry;
	}
	if (key == 115)
	{
		if (cast->map[(int)cast->posy][(int)(cast->posx - cast->dirx)] == 0)
			cast->posx -= cast->dirx;
		if (cast->map[(int)(cast->posy - cast->diry)][(int)cast->posx] == 0)
			cast->posy -= cast->diry;
	}
	if (key == 100)
	{
		if (cast->map[(int)(cast->posy + cast->planey)][(int)cast->posx] == 0)
			cast->posy += cast->planey;
		if (cast->map[(int)cast->posy][(int)(cast->posx + cast->planex)] == 0)
			cast->posx += cast->planex;
	}
	if (key == 97)
	{
		if (cast->map[(int)(cast->posy - cast->planey)][(int)cast->posx] == 0)
			cast->posy -= cast->planey;
		if (cast->map[(int)cast->posy][(int)(cast->posx - cast->planex)] == 0)
			cast->posx -= cast->planex;
	}
	if (key == 65361)
	{
		cast->old_dirx = cast->dirx;
		cast->dirx = (cast->dirx * cos(5 * (cast->pi / 180))) - (cast->diry * sin(5 * (cast->pi / 180)));
		cast->diry = (cast->old_dirx * sin(5 * (cast->pi / 180))) + (cast->diry * cos(5 * (cast->pi / 180)));
		cast->old_planex = cast->planex;
		cast->planex = (cast->planex * cos(5 * (cast->pi / 180))) - (cast->planey * sin(5 * (cast->pi / 180)));
		cast->planey = (cast->old_planex * sin(5 * (cast->pi / 180))) + (cast->planey * cos(5 * (cast->pi / 180)));
	}
	if (key == 65363)
	{
		cast->old_dirx = cast->dirx;
		cast->dirx = (cast->dirx * cos(-(5 * (cast->pi / 180)))) - (cast->diry * sin(-(5 * (cast->pi / 180))));
		cast->diry = (cast->old_dirx * sin(-(5 * (cast->pi / 180)))) + (cast->diry * cos(-(5 * (cast->pi / 180))));
		cast->old_planex = cast->planex;
		cast->planex = (cast->planex * cos(-(5 * (cast->pi / 180)))) - (cast->planey * sin(-(5 * (cast->pi / 180))));
		cast->planey = (cast->old_planex * sin(-(5 * (cast->pi / 180)))) + (cast->planey * cos(-(5 * (cast->pi / 180))));
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

int		ft_key_release(int key, t_cast *cast)
{
	(void)key;
	(void)cast;
	return (0);
}
