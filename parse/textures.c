/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:19:56 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/10 11:44:06 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_fill_x_y(char *buf, parse_t *parse)
{
	char	*line;
	char	**tmp;
	int		i;

	i = 0;
	parse->R = 1;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	parse->i += ft_strlen(line);
	tmp = ft_split(line, ' ');
	if (/*tmp[3] || */ft_is_nbr(tmp[1]) == 0 || ft_is_nbr(tmp[2]) == 0)
		return (ft_error_parsing(4));
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

int		ft_fill_no(char *buf, parse_t *parse)
{
	char	*line;
	char	**tmp;
	int		i;

	i = 0;
	parse->NO = 1;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ');
/*	if (tmp[2])
		return (ft_error_parsing(0));*/
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

int		ft_fill_so(char *buf, parse_t *parse)
{
	char	*line;
	char	**tmp;
	int		i;

	i = 0;
	parse->SO = 1;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ');
/*	if (tmp[2])
		return (ft_error_parsing(1));*/
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

int		ft_fill_we(char *buf, parse_t *parse)
{
	char	*line;
	char	**tmp;
	int		i;

	i = 0;
	parse->WE = 1;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ');
/*	if (tmp[2])
		return (ft_error_parsing(2));*/
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

int		ft_fill_ea(char *buf, parse_t *parse)
{
	char	*line;
	char	**tmp;
	int		i;

	i = 0;
	parse->EA = 1;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ');
/*	if (tmp[2])
		return (ft_error_parsing(3));*/
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
