/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:46:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/28 15:09:57 by lpascrea         ###   ########.fr       */
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
	data_t		data;

	if (ft_argc_argv(argc, argv[1]) == 0)
		return (0);
	parse.fd = open(argv[1], O_RDONLY);
	if (ft_read_map(&parse) == 0)
		return (0);
	ft_setup_data_parse_cast(&parse, &cast);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, parse.x, parse.y, "cub3D");
	data.img = mlx_new_image(data.mlx, parse.x, parse.y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixels, &data.size_line, &data.endian);
	ft_raycasting(&cast, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
