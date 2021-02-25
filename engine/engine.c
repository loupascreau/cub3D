/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:41:32 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/25 12:06:14 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_init_texture(t_cast *cast, t_tex *tex, int w, t_parse *parse)
{
	if (ft_init_tex0(cast, tex, parse, w) == -1)
		return (-1);
	if (ft_init_tex1(cast, tex, parse, w) == -1)
		return (-1);
	if (ft_init_tex2(cast, tex, parse, w) == -1)
		return (-1);
	if (ft_init_tex3(cast, tex, parse, w) == -1)
		return (-1);
	if (ft_init_tex4(cast, tex, parse, w) == -1)
		return (-1);
	ft_free_parse(parse);
	cast->tex = tex;
	return (1);
}

void	ft_exit_prog(t_parse *parse, t_cast *cast)
{
	ft_free_parse(parse);
	ft_free_map(cast);
	mlx_destroy_image(cast->mlx, cast->img);
	mlx_destroy_window(cast->mlx, cast->win);
	mlx_destroy_display(cast->mlx);
	free(cast->mlx);
}

int		ft_engine(t_parse *parse, t_cast *cast)
{
	t_tex	tex[5];

	ft_init_move(cast);
	cast->mlx = mlx_init();
	mlx_get_screen_size(cast->mlx, &cast->sizex, &cast->sizey);
	if (ft_setup_data_parse_cast(parse, cast) == 0)
		return (0);
	cast->win = mlx_new_window(cast->mlx, cast->screen_width,
	cast->screen_height, "cub3D");
	cast->img = mlx_new_image(cast->mlx, cast->screen_width,
	cast->screen_height);
	if (ft_init_texture(cast, tex, 64, parse) < 0)
	{
		ft_exit_prog(parse, cast);
		return (ft_error(7));
	}
	cast->addr = mlx_get_data_addr(cast->img, &cast->bits_per_pixels,
	&cast->size_line, &cast->endian);
	mlx_hook(cast->win, 2, 1L << 0, ft_key_hook, cast);
	mlx_hook(cast->win, 3, 1L << 1, ft_key_release, cast);
	mlx_hook(cast->win, 33, 1L << 0, ft_close_window, cast);
	mlx_loop_hook(cast->mlx, ft_expose, cast);
	mlx_loop(cast->mlx);
	return (1);
}
