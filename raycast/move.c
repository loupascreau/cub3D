/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:57:55 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/20 19:26:53 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_init_move(t_cast *cast)
{
	cast->forward = 0;
	cast->back = 0;
	cast->left = 0;
	cast->right = 0;
	cast->rot_left = 0;
	cast->rot_right = 0;
	cast->echap = 0;
	cast->close = 0;
}

void	ft_rotation(t_cast *cast)
{
	if (cast->rot_right == 1)
	{
		cast->old_dirx = cast->dirx;
		cast->dirx = (cast->dirx * cos(1.5 * (cast->pi / 180))) - (cast->diry * sin(1.5 * (cast->pi / 180)));
		cast->diry = (cast->old_dirx * sin(1.5 * (cast->pi / 180))) + (cast->diry * cos(1.5 * (cast->pi / 180)));
		cast->old_planex = cast->planex;
		cast->planex = (cast->planex * cos(1.5 * (cast->pi / 180))) - (cast->planey * sin(1.5 * (cast->pi / 180)));
		cast->planey = (cast->old_planex * sin(1.5 * (cast->pi / 180))) + (cast->planey * cos(1.5 * (cast->pi / 180)));
	}
	if (cast->rot_left == 1)
	{
		cast->old_dirx = cast->dirx;
		cast->dirx = (cast->dirx * cos(-(1.5 * (cast->pi / 180)))) - (cast->diry * sin(-(1.5 * (cast->pi / 180))));
		cast->diry = (cast->old_dirx * sin(-(1.5 * (cast->pi / 180)))) + (cast->diry * cos(-(1.5 * (cast->pi / 180))));
		cast->old_planex = cast->planex;
		cast->planex = (cast->planex * cos(-(1.5 * (cast->pi / 180)))) - (cast->planey * sin(-(1.5 * (cast->pi / 180))));
		cast->planey = (cast->old_planex * sin(-(1.5 * (cast->pi / 180)))) + (cast->planey * cos(-(1.5 * (cast->pi / 180))));
	}
}

void	ft_left_right(t_cast *cast)
{
	if (cast->right == 1)
	{
		if (cast->map[(int)(cast->posy + cast->planey)][(int)cast->posx] == 0)
			cast->posy += cast->planey / 8;
		if (cast->map[(int)cast->posy][(int)(cast->posx + cast->planex)] == 0)
			cast->posx += cast->planex / 8;
	}
	if (cast->left == 1)
	{
		if (cast->map[(int)(cast->posy - cast->planey)][(int)cast->posx] == 0)
			cast->posy -= cast->planey / 8;
		if (cast->map[(int)cast->posy][(int)(cast->posx - cast->planex)] == 0)
			cast->posx -= cast->planex / 8;
	}
}

void	ft_echap(t_cast *cast)
{
	if (cast->echap == 1)
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
}

void	ft_manage_keys(t_cast *cast)
{
	if (cast->forward == 1)
	{
		if (cast->map[(int)cast->posy][(int)(cast->posx + cast->dirx)] == 0)
			cast->posx += cast->dirx / 8;
		if (cast->map[(int)(cast->posy + cast->diry)][(int)cast->posx] == 0)
			cast->posy += cast->diry / 8;
	}
	if (cast->back == 1)
	{
		if (cast->map[(int)cast->posy][(int)(cast->posx - cast->dirx)] == 0)
			cast->posx -= cast->dirx / 8;
		if (cast->map[(int)(cast->posy - cast->diry)][(int)cast->posx] == 0)
			cast->posy -= cast->diry / 8;
	}
	ft_rotation(cast);
	ft_left_right(cast);
	ft_echap(cast);
}
