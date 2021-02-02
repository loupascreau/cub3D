/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:46:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/01 09:40:55 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

int		ft_check_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '.')
		{
			i++;
			if (argv[i] != 'c' || argv[i + 1] != 'u' || argv[i + 2] != 'b')
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int		ft_argc_argv(int argc, char *argv)
{
	if (argc != 2)
	{
		printf("Error\nMissing '.cub' file\n");
		return (0);
	}
	if (ft_check_argv(argv) == 0)
	{
		printf("Error\nInvalide file, we want .cub\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	parse_t		parse;
	cast_t		cast;

	if (ft_argc_argv(argc, argv[1]) == 0)
		return (0);
	parse.fd = open(argv[1], O_RDONLY);
	if (ft_read_map(&parse) == 0)
		return (0);
	cast.mlx = mlx_init();
	mlx_get_screen_size(cast.mlx, &cast.sizex, &cast.sizey);
	ft_setup_data_parse_cast(&parse, &cast);
	cast.win = mlx_new_window(cast.mlx, cast.screen_width, cast.screen_height, "cub3D");
	cast.img = mlx_new_image(cast.mlx, cast.screen_width, cast.screen_height);
	cast.addr = mlx_get_data_addr(cast.img, &cast.bits_per_pixels, &cast.size_line, &cast.endian);
	mlx_hook(cast.win, 2, 1L << 0, ft_key_hook, &cast);
	mlx_loop_hook(cast.mlx, ft_pixel_put, &cast);
	mlx_loop(cast.mlx);
	return (0);
}
