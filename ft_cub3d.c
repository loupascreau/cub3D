/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:46:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/20 19:37:17 by lpascrea         ###   ########.fr       */
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

int		ft_check_save(char *str, t_cast *cast)
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
	cast->save = 1;
	return (1);
}

int		ft_argc_argv(int argc, char **argv, t_cast *cast)
{
	cast->save = 0;
	if (argc == 1)
		return (ft_error(0));
	if (argc > 3)
		return (ft_error_file(3));
	if (ft_check_argv(argv[1]) == 0)
		return (ft_error(1));
	if (ft_check_save(argv[2], cast) == 0)
		return (ft_error(6));
	return (1);
}

int		main(int argc, char **argv)
{
	t_parse		parse;
	t_cast		cast;

	if (ft_argc_argv(argc, argv, &cast) == 0)
		return (0);
	parse.fd = open(argv[1], O_RDONLY);
	if (ft_read_map(&parse) == 0)
		return (0);
	cast.nbr_sprite = ft_recup_sprites(&parse, &cast);
	if (cast.save == 1)
	{
		if (ft_save(&cast, &parse) == 0)
			return (0);
	}
	else if (ft_engine(&parse, &cast) == 0)
		return (0);
	return (1);
}
