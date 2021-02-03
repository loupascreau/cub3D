/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:46:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/03 18:51:20 by lpascrea         ###   ########.fr       */
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

int		ft_check_save(char *str)
{
	if (!str)
		return (1);
	if (ft_strlen(str) != 6)
		return (0);
	if (str[0] != '-' && str[1] != '-')
		return (0);
	if (str[2] != 's' && str[3] != 'a')
		return (0);
	if (str[4] != 'v' && str[5] != 'e')
		return (0);
	return (1);
}

int		ft_argc_argv(int argc, char **argv)
{
	if (argc == 1 || argc > 3)
		return (ft_error(0));
	if (ft_check_argv(argv[1]) == 0)
		return (ft_error(1));
	if (ft_check_save(argv[2]) == 0)
		return (ft_error(6));
	return (1);
}

int		main(int argc, char **argv)
{
	parse_t		parse;
	cast_t		cast;

	if (ft_argc_argv(argc, argv) == 0)
		return (0);
	parse.fd = open(argv[1], O_RDONLY);
	if (ft_read_map(&parse) == 0)
		return (0);
	if (ft_engine(&parse, &cast) == 0)
		return (0);
	return (1);
}
