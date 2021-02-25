/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:28:42 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/25 13:16:51 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_exit_north(t_parse *parse, char *line, char **tmp)
{
	if (parse->sprite == 1)
		free(parse->s);
	if (parse->east == 1)
		free(parse->ea);
	if (parse->south == 1)
		free(parse->so);
	if (parse->west == 1)
		free(parse->we);
	if (parse->floor == 1)
		free(parse->f);
	if (parse->ceil == 1)
		free(parse->c);
	free(tmp[0]);
	free(tmp);
	free(line);
	return (ft_error_parsing(0));
}

int		ft_exit_south(t_parse *parse, char *line, char **tmp)
{
	if (parse->sprite == 1)
		free(parse->s);
	if (parse->east == 1)
		free(parse->ea);
	if (parse->north == 1)
		free(parse->no);
	if (parse->west == 1)
		free(parse->we);
	if (parse->floor == 1)
		free(parse->f);
	if (parse->ceil == 1)
		free(parse->c);
	free(tmp[0]);
	free(tmp);
	free(line);
	return (ft_error_parsing(1));
}

int		ft_exit_west(t_parse *parse, char *line, char **tmp)
{
	if (parse->sprite == 1)
		free(parse->s);
	if (parse->east == 1)
		free(parse->ea);
	if (parse->south == 1)
		free(parse->so);
	if (parse->north == 1)
		free(parse->no);
	if (parse->floor == 1)
		free(parse->f);
	if (parse->ceil == 1)
		free(parse->c);
	free(tmp[0]);
	free(tmp);
	free(line);
	return (ft_error_parsing(2));
}

int		ft_exit_east(t_parse *parse, char *line, char **tmp)
{
	if (parse->sprite == 1)
		free(parse->s);
	if (parse->north == 1)
		free(parse->no);
	if (parse->south == 1)
		free(parse->so);
	if (parse->west == 1)
		free(parse->we);
	if (parse->floor == 1)
		free(parse->f);
	if (parse->ceil == 1)
		free(parse->c);
	free(tmp[0]);
	free(tmp);
	free(line);
	return (ft_error_parsing(3));
}

int		ft_exit_sprite(t_parse *parse, char *line, char **tmp)
{
	if (parse->north == 1)
		free(parse->no);
	if (parse->east == 1)
		free(parse->ea);
	if (parse->south == 1)
		free(parse->so);
	if (parse->west == 1)
		free(parse->we);
	if (parse->floor == 1)
		free(parse->f);
	if (parse->ceil == 1)
		free(parse->c);
	free(tmp[0]);
	free(tmp);
	free(line);
	return (ft_error_parsing(7));
}
