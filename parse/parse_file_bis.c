/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:43:30 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/27 13:53:17 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_list_params_textures_bis(char *buf, t_parse *parse)
{
	if ((buf[parse->i] == 'W' && buf[parse->i + 1] == 'E') &&
	parse->west == -1)
	{
		if (ft_fill_we(buf, parse) == 0)
			return (0);
	}
	if ((buf[parse->i] == 'E' && buf[parse->i + 1] == 'A') &&
	parse->east == -1)
	{
		if (ft_fill_ea(buf, parse) == 0)
			return (0);
	}
	return (1);
}

int		ft_fill_file(char *buf, t_parse *parse)
{
	while (buf[parse->i])
	{
		if (ft_list_params_textures(buf, parse) == 0)
			return (0);
		if (ft_list_params_colors_xy(buf, parse) == 0)
			return (0);
		if (ft_bad_infos(parse, buf) == 0)
			return (0);
		parse->i++;
	}
	return (1);
}
