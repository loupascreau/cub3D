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

int		ft_bad_infos(t_parse *parse, char *buf)
{
	int	i;

	i = 0;
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
