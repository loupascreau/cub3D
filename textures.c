/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:19:56 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/20 16:25:52 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

void	ft_fill_x_y(char *buf, parse_t *parse)
{
	parse->R = 1;
	parse->i++;
	parse->x = ft_atoi(buf, parse);
	parse->y = ft_atoi(buf, parse);
	ft_last(parse);
	parse->i = 0;
}

void	ft_fill_no(char *buf, parse_t *parse)
{
	int	diff;

	diff = 0;
	parse->NO = 1;
	parse->i += 2;
	while (buf[parse->i] && diff == 0)
	{
		if (buf[parse->i] == '.' && buf[parse->i + 1] == '/')
		{
			while (buf[parse->i] > 32 && buf[parse->i] < 127)
			{
				diff++;
				parse->i++;
			}
			parse->no = ft_substr(buf, (parse->i - diff), diff);
		}
		parse->i++;
	}
	ft_last(parse);
	parse->i = 0;
}

void	ft_fill_so(char *buf, parse_t *parse)
{
	int	diff;

	diff = 0;
	parse->SO = 1;
	parse->i += 2;
	while (buf[parse->i] && diff == 0)
	{
		if (buf[parse->i] == '.' && buf[parse->i + 1] == '/')
		{
			while (buf[parse->i] > 32 && buf[parse->i] < 127)
			{
				diff++;
				parse->i++;
			}
			parse->so = ft_substr(buf, (parse->i - diff), diff);
		}
		parse->i++;
	}
	ft_last(parse);
	parse->i = 0;
}

void	ft_fill_we(char *buf, parse_t *parse)
{
	int	diff;

	diff = 0;
	parse->WE = 1;
	parse->i += 2;
	while (buf[parse->i] && diff == 0)
	{
		if (buf[parse->i] == '.' && buf[parse->i + 1] == '/')
		{
			while (buf[parse->i] > 32 && buf[parse->i] < 127)
			{
				diff++;
				parse->i++;
			}
			parse->we = ft_substr(buf, (parse->i - diff), diff);
		}
		parse->i++;
	}
	ft_last(parse);
	parse->i = 0;
}

void	ft_fill_ea(char *buf, parse_t *parse)
{
	int	diff;

	diff = 0;
	parse->EA = 1;
	parse->i += 2;
	while (buf[parse->i] && diff == 0)
	{
		if (buf[parse->i] == '.' && buf[parse->i + 1] == '/')
		{
			while (buf[parse->i] > 32 && buf[parse->i] < 127)
			{
				diff++;
				parse->i++;
			}
			parse->ea = ft_substr(buf, (parse->i - diff), diff);
		}
		parse->i++;
	}
	ft_last(parse);
	parse->i = 0;
}
