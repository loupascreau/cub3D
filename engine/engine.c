/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:41:32 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/06 15:03:26 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_init_data_texture(tex_t *tex)
{
	tex[0].addr = mlx_get_data_addr(tex[0].img, &tex[0].bits_per_pixels, &tex[0].size_line, &tex[0].endian);
	tex[1].addr = mlx_get_data_addr(tex[1].img, &tex[1].bits_per_pixels, &tex[1].size_line, &tex[1].endian);
	tex[2].addr = mlx_get_data_addr(tex[2].img, &tex[2].bits_per_pixels, &tex[2].size_line, &tex[2].endian);
	tex[3].addr = mlx_get_data_addr(tex[3].img, &tex[3].bits_per_pixels, &tex[3].size_line, &tex[3].endian);
}

int		ft_init_texture(cast_t *cast, tex_t *tex, int w, parse_t *parse)
{
	int h;

	h = w;
	printf("h = %d, w = %d\n", h, w);
	if ((tex[0].img = mlx_xpm_file_to_image(cast->mlx, parse->no, &w, &h)) == NULL)
		return (0);
	if ((tex[1].img = mlx_xpm_file_to_image(cast->mlx, parse->so, &w, &h)) == NULL)
		return (0);
	if ((tex[2].img = mlx_xpm_file_to_image(cast->mlx, parse->ea, &w, &h)) == NULL)
		return (0);
	if ((tex[3].img = mlx_xpm_file_to_image(cast->mlx, parse->we, &w, &h)) == NULL)
		return (0);
	tex[4].img = NULL;
	ft_init_data_texture(tex);
	cast->tex = tex;
	return (1);
}

int		ft_engine(parse_t *parse, cast_t *cast)
{	
	tex_t	tex[5];

	cast->mlx = mlx_init();
	mlx_get_screen_size(cast->mlx, &cast->sizex, &cast->sizey);
	if (ft_setup_data_parse_cast(parse, cast) == 0)
		return (0);
	cast->win = mlx_new_window(cast->mlx, cast->screen_width, cast->screen_height, "cub3D");
	if (ft_init_texture(cast, tex, 64, parse) == 0)
		return (ft_error(7));
	mlx_hook(cast->win, 2, 1L << 0, ft_key_hook, cast);
	mlx_hook(cast->win, 33, 1L << 0, ft_close_window, cast);
	mlx_loop_hook(cast->mlx, ft_expose, cast);
	mlx_loop(cast->mlx);
	return (1);
}
