/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:28:42 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/26 19:03:17 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_exit_north(t_parse *parse, char *line, char **tmp, int count)
{
	int i;

	i = 1;
	if (parse->sprite >= 0)
		free(parse->s);
	if (parse->east >= 0)
		free(parse->ea);
	if (parse->south >= 0)
		free(parse->so);
	if (parse->west >= 0)
		free(parse->we);
	if (parse->floor >= 0)
		free(parse->f);
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
	return (ft_error_parsing(0));
}

int		ft_exit_south(t_parse *parse, char *line, char **tmp, int count)
{
	int i;

	i = 1;
	if (parse->sprite >= 0)
		free(parse->s);
	if (parse->east >= 0)
		free(parse->ea);
	if (parse->north >= 0)
		free(parse->no);
	if (parse->west >= 0)
		free(parse->we);
	if (parse->floor >= 0)
		free(parse->f);
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
	return (ft_error_parsing(1));
}

int		ft_exit_west(t_parse *parse, char *line, char **tmp, int count)
{
	int i;

	i = 1;
	if (parse->sprite >= 0)
		free(parse->s);
	if (parse->east >= 0)
		free(parse->ea);
	if (parse->south >= 0)
		free(parse->so);
	if (parse->north >= 0)
		free(parse->no);
	if (parse->floor >= 0)
		free(parse->f);
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
	return (ft_error_parsing(2));
}

int		ft_exit_east(t_parse *parse, char *line, char **tmp, int count)
{
	int i;

	i = 1;
	if (parse->sprite >= 0)
		free(parse->s);
	if (parse->north >= 0)
		free(parse->no);
	if (parse->south >= 0)
		free(parse->so);
	if (parse->west >= 0)
		free(parse->we);
	if (parse->floor >= 0)
		free(parse->f);
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
	return (ft_error_parsing(3));
}

int		ft_exit_sprite(t_parse *parse, char *line, char **tmp, int count)
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
	if (parse->floor >= 0)
		free(parse->f);
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
	return (ft_error_parsing(7));
}
