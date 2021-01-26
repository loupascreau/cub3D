/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:18:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/26 11:16:27 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

void	ft_init(parse_t *parse)
{
	parse->R = 0;
	parse->NO = 0;
	parse->SO = 0;
	parse->WE = 0;
	parse->EA = 0;
	parse->S = 0;
	parse->F = 0;
	parse->C = 0;
	parse->last = 0;
	parse->posX = 0;
	parse->posY = 0;
}

int		ft_map_at_end(char *buf, parse_t *parse)
{
	if (parse->R == 1 && parse->NO == 1 && parse->SO == 1 && parse->WE == 1)
	{
		if (parse->EA == 1 && parse->S == 1 && parse->F == 1 && parse->C == 1)
		{
			parse->i = parse->last;
			while (buf[parse->i] != '1' && buf[parse->i])
				parse->i++;
			while (buf[parse->i - 1] != '\n')
				parse->i--;
			if (ft_parse_map(buf, parse) == 0) 
				return (0);
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

void	ft_list_params(char *buf, parse_t *parse)
{
	if (buf[parse->i] == 'R' && parse->R == 0)
		ft_fill_x_y(buf, parse);
	if ((buf[parse->i] == 'N' && buf[parse->i + 1] == 'O') && parse->NO == 0)
		ft_fill_no(buf, parse);
	if ((buf[parse->i] == 'S' && buf[parse->i + 1] == 'O') && parse->SO == 0)
		ft_fill_so(buf, parse);
	if ((buf[parse->i] == 'W' && buf[parse->i + 1] == 'E') && parse->WE == 0)
		ft_fill_we(buf, parse);
	if ((buf[parse->i] == 'E' && buf[parse->i + 1] == 'A') && parse->EA == 0)
		ft_fill_ea(buf, parse);
	if (buf[parse->i] == 'S' && parse->S == 0)
		ft_fill_s(buf, parse);
	if (buf[parse->i] == 'F' && parse->F == 0)
		ft_fill_f(buf, parse);
	if (buf[parse->i] == 'C' && parse->C == 0)
		ft_fill_c(buf, parse);
}

int		ft_read_map(parse_t *parse)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	ft_init(parse);
	if ((ret = read(parse->fd, buf, BUFFER_SIZE)) < 1)
		return (0);
	parse->i = 0;
	buf[ret] = '\0';
	while (buf[parse->i])
	{
		ft_list_params(buf, parse);
		parse->i++;
	}
	if (ft_map_at_end(buf, parse) == 0)
	{
		printf("Error\nMap isn't closed or she's not at end\n");
		return (0);
	}
	if	(ft_find_player(parse) == 0)
	{
		printf("Error\nYour map is missing starter coordinates\n");
		return (0);
	}
	int i = 0;
	while (parse->tab[i])
	{
		printf("tab[%d] =	%s\n", i, parse->tab[i]);
		i++;
	}
	printf("coordinates begin = [%d, %d]\n", parse->posY, parse->posX);
	printf("x = %d, y = %d\n", parse->x, parse->y);
	printf("parse->no = %s\n", parse->no);
	printf("parse->so = %s\n", parse->so);
	printf("parse->we = %s\n", parse->we);
	printf("parse->ea = %s\n", parse->ea);
	printf("parse->s = %s\n", parse->s);
	printf("parse->f = %s\n", parse->f);
	printf("parse->c = %s\n", parse->c);
	return (1);
}
