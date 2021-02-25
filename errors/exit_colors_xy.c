/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_colors_xy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:50:21 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/25 13:28:34 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_exit_xy(t_parse *parse, char *line, char **tmp, int count)
{
	if (parse->north == 1)
		free(parse->no);
	if (parse->east == 1)
		free(parse->ea);
	if (parse->south == 1)
		free(parse->so);
	if (parse->west == 1)
		free(parse->we);
	if (parse->sprite == 1)
		free(parse->s);
	if (parse->floor == 1)
		free(parse->f);
	if (parse->ceil == 1)
		free(parse->c);
	free(tmp[0]);
	if (count == 2)
		free(tmp[1]);
	free(tmp);
	free(line);
	return (ft_error_parsing(4));
}

int		ft_exit_floor(t_parse *parse, char *line, char **tmp, int count)
{
	if (parse->north == 1)
		free(parse->no);
	if (parse->east == 1)
		free(parse->ea);
	if (parse->south == 1)
		free(parse->so);
	if (parse->west == 1)
		free(parse->we);
	if (parse->sprite == 1)
		free(parse->s);
	if (parse->ceil == 1)
		free(parse->c);
	free(tmp[0]);
	if (count == 2)
		free(tmp[1]);
	free(tmp);
	free(line);
	return (ft_error_parsing(6));
}

int		ft_exit_ceil(t_parse *parse, char *line, char **tmp, int count)
{
	if (parse->north == 1)
		free(parse->no);
	if (parse->east == 1)
		free(parse->ea);
	if (parse->south == 1)
		free(parse->so);
	if (parse->west == 1)
		free(parse->we);
	if (parse->sprite == 1)
		free(parse->s);
	if (parse->floor == 1)
		free(parse->f);
	free(tmp[0]);
	if (count == 2)
		free(tmp[1]);
	free(tmp);
	free(line);
	return (ft_error_parsing(5));
}
