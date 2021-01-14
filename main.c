/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:46:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/14 10:42:29 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

int		main(int argc, char **argv)
{
	parse_t		parse;

	(void)argv;
	if (argc != 2)
	{
		printf("nombre darguments Error\n");
		return (0);
	}
	parse.fd = open(argv[1], O_RDONLY);
	if (ft_read_map(&parse) == 0)
		return (0);
	return (0);
}
