/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_colors_xy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:50:21 by lpascrea          #+#    #+#             */
/*   Updated: 2021/03/01 16:53:05 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_exit_xy(t_parse *parse, char *line, char **tmp, int count)
{
	int i;

	i = 0;
	if (parse->north >= 0)
		free(parse->no);
	if (parse->east >= 0)
		free(parse->ea);
	if (parse->south >= 0)
		free(parse->so);
	if (parse->west >= 0)
		free(parse->we);
	if (parse->sprite >= 0)
		free(parse->s);
	if (parse->floor >= 0)
		free(parse->f);
	if (parse->ceil >= 0)
		free(parse->c);
	while (i < count)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	free(line);
	return (ft_error_parsing(4));
}

int		ft_exit_floor(t_parse *parse, char *line, char **tmp, int count)
{
	int i;

	i = 1;
	if (parse->north >= 0)
		free(parse->no);
	if (parse->east >= 0)
		free(parse->ea);
	if (parse->south >= 0)
		free(parse->so);
	if (parse->west >= 0)
		free(parse->we);
	if (parse->sprite >= 0)
		free(parse->s);
	if (parse->ceil >= 0)
		free(parse->c);
	while (i < count)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp[0]);
	free(tmp);
	free(line);
	return (ft_error_parsing(6));
}

int		ft_exit_ceil(t_parse *parse, char *line, char **tmp, int count)
{
	int i;

	i = 1;
	if (parse->north >= 0)
		free(parse->no);
	if (parse->east >= 0)
		free(parse->ea);
	if (parse->south >= 0)
		free(parse->so);
	if (parse->west >= 0)
		free(parse->we);
	if (parse->sprite >= 0)
		free(parse->s);
	if (parse->floor >= 0)
		free(parse->f);
	while (i < count)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp[0]);
	free(tmp);
	free(line);
	return (ft_error_parsing(5));
}

int		ft_exit_double(t_parse *parse, int nbr)
{
	if (parse->north >= 0)
		free(parse->no);
	if (parse->east >= 0)
		free(parse->ea);
	if (parse->south >= 0)
		free(parse->so);
	if (parse->west >= 0)
		free(parse->we);
	if (parse->sprite >= 0)
		free(parse->s);
	if (parse->floor >= 0)
		free(parse->f);
	if (parse->ceil >= 0)
		free(parse->c);
	return (ft_error_file(nbr));
}

int		ft_exit_cf(t_parse *parse, char **tmp, int count)
{
	int i;

	i = 1;
	if (parse->north >= 0)
		free(parse->no);
	if (parse->east >= 0)
		free(parse->ea);
	if (parse->south >= 0)
		free(parse->so);
	if (parse->west >= 0)
		free(parse->we);
	if (parse->sprite >= 0)
		free(parse->s);
	if (parse->ceil >= 0)
		free(parse->c);
	if (parse->floor >= 0)
		free(parse->f);
	while (i < count)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp[0]);
	free(tmp);
	return (ft_error_parsing(11));
}
