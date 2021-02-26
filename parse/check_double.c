/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:16:25 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/26 13:58:18 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_check_double(char *buf, t_parse *parse)
{
	if ((buf[parse->i] == 'N' && buf[parse->i + 1] == 'O') && (parse->i != parse->north && parse->north > 0))
		return (0);
	if ((buf[parse->i] == 'S' && buf[parse->i + 1] == 'O') && (parse->i != parse->south && parse->south > 0))
		return (0);
	if ((buf[parse->i] == 'W' && buf[parse->i + 1] == 'E') && (parse->i != parse->west && parse->west > 0))
		return (0);
	if ((buf[parse->i] == 'E' && buf[parse->i + 1] == 'A') && (parse->i != parse->east && parse->east > 0))
		return (0);
	if (buf[parse->i] == 'S'  && buf[parse->i + 1] == ' ' && (parse-> i != parse->sprite && parse->sprite > 0))
		return (0);
	if (buf[parse->i] == 'R' && (parse->i != parse->reso && parse->reso > 0))
		return (0);
	if (buf[parse->i] == 'F' && (parse->i != parse->floor && parse->floor > 0))
		return (0);
	if (buf[parse->i] == 'C' && (parse->i != parse->ceil && parse->ceil > 0))
		return (0);
	return (1);
}
