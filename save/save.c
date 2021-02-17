/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:50:28 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/17 14:50:40 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_init_save(t_cast *cast, t_save *save)
{
	int x;
	int	y;

	x = cast->screen_width;
	y = cast->screen_height;
	save->b = 'B';
	save->m = 'M';
	save->size_file = (54 + (4 * x * y));
	save->offset = 54;
	save->size_img_header = 40;
	save->img_width = x;
	save->img_height = y;
	save->plane = 1;
	save->bpp = 32;
	save->size_img = 4 * x * y;
}

void	ft_fill_img(t_cast *cast, t_save *save)
{
	int	x;
	int	y;
	int	line;

	y = cast->screen_height;
	while (y > 0)
	{
		x = 0;
		while (x < cast->screen_width)
		{
			line = x * 4 + 4 * cast->screen_width * y;
			write(save->fd, &cast->addr[line], 4);
			x++;
		}
		y--;
	}
}

void	ft_write_bmp(t_cast *cast, t_save *save)
{
	ft_init_save(cast, save);
	save->fd = open("save.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	write(save->fd, &save->b, 1);
	write(save->fd, &save->m, 1);
	write(save->fd, &save->size_file, 4);
	write(save->fd, "\0\0\0\0", 4);
	write(save->fd, &save->offset, 4);
	write(save->fd, &save->size_img_header, 4);
	write(save->fd, &save->img_width, 4);
	write(save->fd, &save->img_height, 4);
	write(save->fd, &save->plane, 2);
	write(save->fd, &save->bpp, 2);
	write(save->fd, "\0\0\0\0", 4);
	write(save->fd, &save->size_img, 4);
	write(save->fd, "\0\0\0\0", 4);
	write(save->fd, "\0\0\0\0", 4);
	write(save->fd, "\0\0\0\0", 4);
	write(save->fd, "\0\0\0\0", 4);
	ft_fill_img(cast, save);
}

int		ft_initialisation(t_cast *cast, t_parse *parse, t_tex *tex)
{
	int		ret;

	cast->mlx = mlx_init();
	mlx_get_screen_size(cast->mlx, &cast->sizex, &cast->sizey);
	if (ft_setup_data_parse_cast(parse, cast) == 0)
		return (0);
	cast->img = mlx_new_image(cast->mlx, cast->screen_width,
	cast->screen_height);
	cast->addr = mlx_get_data_addr(cast->img, &cast->bits_per_pixels,
	&cast->size_line, &cast->endian);
	my_mlx_pixel_put(cast);
	if ((ret = ft_init_texture(cast, tex, 64, parse)) < 0)
	{
		ft_free_parse(parse);
		cast->miss_texture = ret;
		return (ft_error(7));
	}
	if (ft_raycasting(cast) == 0)
		return (0);
	ft_sprite(cast);
	free(cast->buffer);
	return (1);
}

int		ft_save(t_cast *cast, t_parse *parse)
{
	t_save	save;
	t_tex	tex[5];

	if (ft_initialisation(cast, parse, tex) == 0)
		return (0);
	ft_write_bmp(cast, &save);
	ft_free_map(cast);
	mlx_loop_end(cast->mlx);
	mlx_destroy_image(cast->mlx, cast->img);
	mlx_destroy_image(cast->mlx, cast->tex[0].img);
	mlx_destroy_image(cast->mlx, cast->tex[1].img);
	mlx_destroy_image(cast->mlx, cast->tex[2].img);
	mlx_destroy_image(cast->mlx, cast->tex[3].img);
	mlx_destroy_image(cast->mlx, cast->tex[4].img);
	mlx_destroy_display(cast->mlx);
	free(cast->mlx);
	exit(0);
	return (0);
}
