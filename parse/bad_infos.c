/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:20:43 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/27 15:56:46 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_after_new_line(t_parse *parse, char *buf, int i)
{
	i = parse->i + 1;
	while (buf[i] == ' ')
		i++;
	if (buf[i] == '\0')
		return (1);
	if ((buf[i] != 'S' && buf[i + 1] != 'O') && (buf[i] != 'N' &&
	buf[i + 1] != 'O') && (buf[i] != 'E' && buf[i + 1] != 'A') &&
	(buf[i] != 'W' && buf[i + 1] != 'E') && (buf[i] != 'S' &&
	buf[i + 1] != ' ') && buf[i] != 'C' && buf[i] != 'F' && buf[i] != '\t' &&
	buf[i] != 'R' && buf[i] != ' ' && buf[i] != '\n' && parse->last >= i)
		return (ft_exit_double(parse, 2));
	return (1);
}

int		ft_exit_bad_id(t_parse *parse, int nbr)
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
	return (ft_error_parsing(nbr));
}

int		ft_check_id(t_parse *parse, char *buf)
{
	if (buf[parse->i] == 'S' && (buf[parse->i + 1] != ' ' &&
	buf[parse->i + 1] != 'O') && parse->i <= parse->last)
		return (ft_exit_bad_id(parse, 7));
	if (buf[parse->i] == 'W' && buf[parse->i + 1] == 'E' &&
	buf[parse->i + 2] != ' ' && parse->i <= parse->last)
		return (ft_exit_bad_id(parse, 2));
	if (buf[parse->i] == 'E' && buf[parse->i + 1] == 'A' &&
	buf[parse->i + 2] != ' ' && parse->i <= parse->last)
		return (ft_exit_bad_id(parse, 3));
	if (buf[parse->i] == 'N' && buf[parse->i + 1] == 'O' &&
	buf[parse->i + 2] != ' ' && parse->i <= parse->last)
		return (ft_exit_bad_id(parse, 0));
	if (buf[parse->i] == 'S' && buf[parse->i + 1] == 'O' &&
	buf[parse->i + 2] != ' ' && parse->i <= parse->last)
		return (ft_exit_bad_id(parse, 1));
	if (buf[parse->i] == 'R' && buf[parse->i + 1] != ' ' &&
	parse->i <= parse->last)
		return (ft_exit_bad_id(parse, 4));
	return (1);
}

int		ft_bad_infos(t_parse *parse, char *buf)
{
	int	i;

	i = 0;
	if (ft_check_id(parse, buf) == 0)
		return (0);
	if (parse->i == 0)
	{
		i = parse->i;
		while (buf[i] == ' ')
			i++;
		if ((buf[i] != 'S' && buf[i + 1] != 'O') && (buf[i] != 'N' &&
		buf[i + 1] != 'O') && (buf[i] != 'E' && buf[i + 1] != 'A') &&
		(buf[i] != 'W' && buf[i + 1] != 'E') && (buf[i] != 'S' &&
		buf[i + 1] != ' ') && buf[i] != 'C' && buf[i] != 'F' && buf[i] != '\t'
		&& buf[i] != 'R' && buf[i] != ' ' && buf[i] != '\n' && i <= parse->last)
			return (ft_exit_double(parse, 2));
	}
	if (buf[parse->i] == '\n')
	{
		if (ft_after_new_line(parse, buf, i) == 0)
			return (0);
	}
	return (1);
}
