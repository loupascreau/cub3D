/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:19:56 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/26 19:01:46 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_fill_x_y(char *buf, t_parse *parse)
{
	char	*line;
	char	**tmp;
	int		count;
	int		i;

	count = 0;
	i = 0;
	parse->reso = parse->i;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	parse->i += ft_strlen(line);
	tmp = ft_split(line, ' ', &count);
	if (count != 3 || ft_is_nbr(tmp[1]) == 0 || ft_is_nbr(tmp[2]) == 0)
		return (ft_exit_xy(parse, line, tmp, count));
	parse->x = ft_atoi(tmp[1]);
	free(tmp[1]);
	parse->y = ft_atoi(tmp[2]);
	free(tmp[2]);
	free(tmp[0]);
	free(tmp);
	free(line);
	ft_last(parse);
	parse->i = 0;
	return (1);
}

int		ft_fill_no(char *buf, t_parse *parse)
{
	char	*line;
	char	**tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	parse->north = parse->i;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ', &count);
	if (count != 2)
		return (ft_exit_north(parse, line, tmp, count));
	parse->no = ft_strdup(tmp[1]);
	parse->i += ft_strlen(line);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	free(line);
	ft_last(parse);
	parse->i = 0;
	return (1);
}

int		ft_fill_so(char *buf, t_parse *parse)
{
	char	*line;
	char	**tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	parse->south = parse->i;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ', &count);
	if (count != 2)
		return (ft_exit_south(parse, line, tmp, count));
	parse->so = ft_strdup(tmp[1]);
	parse->i += ft_strlen(line);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	free(line);
	ft_last(parse);
	parse->i = 0;
	return (1);
}

int		ft_fill_we(char *buf, t_parse *parse)
{
	char	*line;
	char	**tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	parse->west = parse->i;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ', &count);
	if (count != 2)
		return (ft_exit_west(parse, line, tmp, count));
	parse->we = ft_strdup(tmp[1]);
	parse->i += ft_strlen(line);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	free(line);
	ft_last(parse);
	parse->i = 0;
	return (1);
}

int		ft_fill_ea(char *buf, t_parse *parse)
{
	char	*line;
	char	**tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	parse->east = parse->i;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ', &count);
	if (count != 2)
		return (ft_exit_east(parse, line, tmp, count));
	parse->ea = ft_strdup(tmp[1]);
	parse->i += ft_strlen(line);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	free(line);
	ft_last(parse);
	parse->i = 0;
	return (1);
}
