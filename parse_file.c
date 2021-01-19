/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:18:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/18 11:22:03 by lpascrea         ###   ########.fr       */
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
}

int		ft_only_map(char *buf, parse_t *parse)
{
	if (parse->R == 1 && parse->NO == 1 && parse->SO == 1 && parse->WE == 1)
	{
		if (parse->EA == 1 && parse->S == 1 && parse->F == 1 && parse->C == 1)
		{
			parse->i = parse->last;	
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
		if (buf[parse->i] == 'R' && parse->R == 0)
			ft_fill_x_y(buf, parse);
		if ((buf[parse->i] == 'N' && buf[parse->i + 1] == 'O') && parse->NO == 0)
			ft_fill_NO(buf, parse);
		if ((buf[parse->i] == 'S' && buf[parse->i + 1] == 'O') && parse->SO == 0)
			ft_fill_SO(buf, parse);
		if ((buf[parse->i] == 'W' && buf[parse->i + 1] == 'E') && parse->WE == 0)
			ft_fill_WE(buf, parse);
		if ((buf[parse->i] == 'E' && buf[parse->i + 1] == 'A') && parse->EA == 0)
			ft_fill_EA(buf, parse);
		if (buf[parse->i] == 'S' && parse->S == 0)
			ft_fill_S(buf, parse);
		if (buf[parse->i] == 'F' && parse->F == 0)
			ft_fill_F(buf, parse);
		if (buf[parse->i] == 'C' && parse->C == 0)
			ft_fill_C(buf, parse);
		parse->i++;
	}
	if (ft_only_map(buf, parse) == 0)
	{
		printf("Error .cub\n");
		return (0);
	}
	printf("x = %d, y = %d\n", parse->x, parse->y);
	printf("parse->no = %s\n", parse->no);
	printf("parse->so = %s\n", parse->so);
	printf("parse->we = %s\n", parse->we);
	printf("parse->ea = %s\n", parse->ea);
	printf("parse->s = %s\n", parse->s);
	printf("parse->f = %s\n", parse->f);
	printf("parse->c = %s\n", parse->c);
	return (0);
}
