/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:41:32 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/03 14:48:31 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_engine(parse_t *parse, cast_t *cast)
{
	cast->mlx = mlx_init();
	mlx_get_screen_size(cast->mlx, &cast->sizex, &cast->sizey);
	if (ft_setup_data_parse_cast(parse, cast) == 0)
			return (0);
	cast->win = mlx_new_window(cast->mlx, cast->screen_width, cast->screen_height, "cub3D");
	cast->img = mlx_new_image(cast->mlx, cast->screen_width, cast->screen_height);
	cast->addr = mlx_get_data_addr(cast->img, &cast->bits_per_pixels, &cast->size_line, &cast->endian);
	mlx_hook(cast->win, 2, 1L << 0, ft_key_hook, cast);
	mlx_loop_hook(cast->mlx, ft_pixel_put, cast);
	mlx_loop(cast->mlx);
	return (1);
}
