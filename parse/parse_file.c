/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:18:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/27 13:59:00 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_init(t_parse *parse)
{
	parse->reso = -1;
	parse->north = -1;
	parse->south = -1;
	parse->west = -1;
	parse->east = -1;
	parse->sprite = -1;
	parse->floor = -1;
	parse->ceil = -1;
	parse->last = 0;
	parse->posx = 0;
	parse->posy = 0;
	parse->longest = 0;
	parse->height = 0;
	parse->dirx = 0;
	parse->diry = 0;
	parse->letter = 0;
	parse->planex = 0;
	parse->planey = 0;
}

int		ft_map_at_end(char *buf, t_parse *parse)
{
	if (parse->reso >= 0 && parse->north >= 0 &&
	parse->south >= 0 && parse->west >= 0)
	{
		if (parse->east >= 0 && parse->sprite >= 0 &&
		parse->floor >= 0 && parse->ceil >= 0)
		{
			parse->i = parse->last;
			while (buf[parse->i] != '1' && buf[parse->i])
			{
				if (buf[parse->i] != ' ' && buf[parse->i] != '\n')
					return (ft_exit_parse_file_bis(parse));
				parse->i++;
			}
			while (buf[parse->i - 1] != '\n')
				parse->i--;
			if (ft_parse_map(buf, parse) == 0)
				return (0);
			return (1);
		}
	}
	return (ft_exit_parse_file(parse));
}

int		ft_list_params_textures(char *buf, t_parse *parse)
{
	if (ft_check_double(buf, parse) == 0)
		return (ft_exit_double(parse, 1));
	if ((buf[parse->i] == 'N' && buf[parse->i + 1] == 'O') &&
	parse->north == -1)
	{
		if (ft_fill_no(buf, parse) == 0)
			return (0);
	}
	if ((buf[parse->i] == 'S' && buf[parse->i + 1] == 'O') &&
	parse->south == -1)
	{
		if (ft_fill_so(buf, parse) == 0)
			return (0);
	}
	if (ft_list_params_textures_bis(buf, parse) == 0)
		return (0);
	return (1);
}

int		ft_list_params_colors_xy(char *buf, t_parse *parse)
{
	if (ft_check_double(buf, parse) == 0)
		return (ft_exit_double(parse, 1));
	if (buf[parse->i] == 'S' && buf[parse->i + 1] == ' ' &&
	parse->sprite == -1)
	{
		if (ft_fill_s(buf, parse) == 0)
			return (0);
	}
	if (buf[parse->i] == 'R' && parse->reso == -1)
	{
		if (ft_fill_x_y(buf, parse) == 0)
			return (0);
	}
	if (buf[parse->i] == 'F' && parse->floor == -1)
	{
		if (ft_fill_f(buf, parse) == 0)
			return (0);
	}
	if (buf[parse->i] == 'C' && parse->ceil == -1)
	{
		if (ft_fill_c(buf, parse) == 0)
			return (0);
	}
	return (1);
}

int		ft_read_map(t_parse *parse)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	ft_init(parse);
	if (parse->fd < 0)
		return (ft_error(2));
	if ((ret = read(parse->fd, buf, BUFFER_SIZE)) < 1)
	{
		if (errno == 21)
		{
			perror("Error\nYour .cub");
			return (0);
		}
		return (ft_error(5));
	}
	parse->i = 0;
	buf[ret] = '\0';
	if (ft_fill_file(buf, parse) == 0)
		return (0);
	if (ft_map_at_end(buf, parse) == 0)
		return (0);
	if (parse->x == 0 || parse->y == 0)
		return (ft_exit_file(parse));
	return (1);
}
