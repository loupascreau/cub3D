/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:45:28 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/27 16:01:21 by lpascrea         ###   ########.fr       */
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
		cast->forward = 1;
	if (key == 115)
		cast->back = 1;
	if (key == 100)
		cast->right = 1;
	if (key == 97)
		cast->left = 1;
	if (key == 65363)
		cast->rot_right = 1;
	if (key == 65361)
		cast->rot_left = 1;
	if (key == 65307)
		cast->echap = 1;
	return (0);
}

int		ft_key_release(int key, t_cast *cast)
{
	if (key == 119)
		cast->forward = 0;
	if (key == 115)
		cast->back = 0;
	if (key == 100)
		cast->right = 0;
	if (key == 97)
		cast->left = 0;
	if (key == 65363)
		cast->rot_right = 0;
	if (key == 65361)
		cast->rot_left = 0;
	if (key == 65307)
		cast->echap = 0;
	return (0);
}
