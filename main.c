/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:46:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/21 11:04:06 by lpascrea         ###   ########.fr       */
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

	if (ft_argc_argv(argc, argv[1]) == 0)
		return (0);
	parse.fd = open(argv[1], O_RDONLY);
	if (ft_read_map(&parse) == 0)
		return (0);
	return (0);
}
