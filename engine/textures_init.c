/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:34:38 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/25 11:58:41 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_init_tex0(t_cast *cast, t_tex *tex, t_parse *parse, int w)
{
	if ((tex[0].img = mlx_xpm_file_to_image(cast->mlx,
	parse->no, &w, &w)) == NULL)
		return (-1);
	tex[0].addr = mlx_get_data_addr(tex[0].img,
	&tex[0].bits_per_pixels, &tex[0].size_line, &tex[0].endian);
	return (0);
}

int		ft_init_tex1(t_cast *cast, t_tex *tex, t_parse *parse, int w)
{
	if ((tex[1].img = mlx_xpm_file_to_image(cast->mlx,
	parse->so, &w, &w)) == NULL)
	{
		mlx_destroy_image(cast->mlx, tex[0].img);
		return (-1);
	}
	tex[1].addr = mlx_get_data_addr(tex[1].img,
	&tex[1].bits_per_pixels, &tex[1].size_line, &tex[1].endian);
	return (0);
}

int		ft_init_tex2(t_cast *cast, t_tex *tex, t_parse *parse, int w)
{
	if ((tex[2].img = mlx_xpm_file_to_image(cast->mlx,
	parse->we, &w, &w)) == NULL)
	{
		mlx_destroy_image(cast->mlx, tex[0].img);
		mlx_destroy_image(cast->mlx, tex[1].img);
		return (-1);
	}
	tex[2].addr = mlx_get_data_addr(tex[2].img,
	&tex[2].bits_per_pixels, &tex[2].size_line, &tex[2].endian);
	return (0);
}

int		ft_init_tex3(t_cast *cast, t_tex *tex, t_parse *parse, int w)
{
	if ((tex[3].img = mlx_xpm_file_to_image(cast->mlx,
	parse->ea, &w, &w)) == NULL)
	{
		mlx_destroy_image(cast->mlx, tex[0].img);
		mlx_destroy_image(cast->mlx, tex[1].img);
		mlx_destroy_image(cast->mlx, tex[2].img);
		return (-1);
	}
	tex[3].addr = mlx_get_data_addr(tex[3].img,
	&tex[3].bits_per_pixels, &tex[3].size_line, &tex[3].endian);
	return (0);
}

int		ft_init_tex4(t_cast *cast, t_tex *tex, t_parse *parse, int w)
{
	if ((tex[4].img = mlx_xpm_file_to_image(cast->mlx,
	parse->s, &w, &w)) == NULL)
	{
		mlx_destroy_image(cast->mlx, tex[0].img);
		mlx_destroy_image(cast->mlx, tex[1].img);
		mlx_destroy_image(cast->mlx, tex[2].img);
		mlx_destroy_image(cast->mlx, tex[3].img);
		return (-1);
	}
	tex[4].addr = mlx_get_data_addr(tex[4].img,
	&tex[4].bits_per_pixels, &tex[4].size_line, &tex[4].endian);
	return (0);
}
