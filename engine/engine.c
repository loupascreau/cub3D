/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:41:32 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/13 09:03:23 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_init_data_texture(tex_t *tex)
{
	tex[0].addr = mlx_get_data_addr(tex[0].img, &tex[0].bits_per_pixels, &tex[0].size_line, &tex[0].endian);
	tex[1].addr = mlx_get_data_addr(tex[1].img, &tex[1].bits_per_pixels, &tex[1].size_line, &tex[1].endian);
	tex[2].addr = mlx_get_data_addr(tex[2].img, &tex[2].bits_per_pixels, &tex[2].size_line, &tex[2].endian);
	tex[3].addr = mlx_get_data_addr(tex[3].img, &tex[3].bits_per_pixels, &tex[3].size_line, &tex[3].endian);
	tex[4].addr = mlx_get_data_addr(tex[4].img, &tex[4].bits_per_pixels, &tex[4].size_line, &tex[4].endian);
}

int		ft_init_texture(cast_t *cast, tex_t *tex, int w, parse_t *parse)
{
	int h;

	h = w;
	if ((tex[0].img = mlx_xpm_file_to_image(cast->mlx, parse->no, &w, &h)) == NULL)
		return (-1);
	if ((tex[1].img = mlx_xpm_file_to_image(cast->mlx, parse->so, &w, &h)) == NULL)
		return (-1);
	if ((tex[2].img = mlx_xpm_file_to_image(cast->mlx, parse->ea, &w, &h)) == NULL)
		return (-1);
	if ((tex[3].img = mlx_xpm_file_to_image(cast->mlx, parse->we, &w, &h)) == NULL)
		return (-1);
	if ((tex[4].img = mlx_xpm_file_to_image(cast->mlx, parse->s, &w, &h)) == NULL)
		return (-1);
	free(parse->no);
	free(parse->so);
	free(parse->ea);
	free(parse->we);
	free(parse->s);
	ft_init_data_texture(tex);
	cast->tex = tex;
	return (1);
}

int		ft_engine(parse_t *parse, cast_t *cast)
{	
	tex_t	tex[5];
	int		ret;

	cast->mlx = mlx_init();
	mlx_get_screen_size(cast->mlx, &cast->sizex, &cast->sizey);
	if (ft_setup_data_parse_cast(parse, cast) == 0)
		return (0);
	cast->win = mlx_new_window(cast->mlx, cast->screen_width, cast->screen_height, "cub3D");
	cast->img = mlx_new_image(cast->mlx, cast->screen_width, cast->screen_height);
	cast->addr = mlx_get_data_addr(cast->img, &cast->bits_per_pixels, &cast->size_line, &cast->endian);
	if ((ret = ft_init_texture(cast, tex, 64, parse)) == 0)
		return (ft_error(7));
	if (ret == -1)
		cast->miss_texture = -1;
	mlx_hook(cast->win, 2, 1L << 0, ft_key_hook, cast);
	mlx_hook(cast->win, 3, 1L << 1, ft_key_release, cast);
	mlx_hook(cast->win, 33, 1L << 0, ft_close_window, cast);
	mlx_loop_hook(cast->mlx, ft_expose, cast);
	mlx_loop(cast->mlx);
	return (1);
}
