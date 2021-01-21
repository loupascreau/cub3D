/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:49:35 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/20 16:45:21 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

int		ft_check_line(char *line1, char *line2)
{
	index_t	index;

	ft_init_index(&index);
	while (line1[index.i] != '1')
		index.i++;
	while (line2[index.j])
	{
		if (index.j == index.i && line1[index.i] != '1' && line2[index.j] != '1')
			return (0);
		index.check = ft_check_all_line(line1, line2, &index);
		if (index.check == 0)
			return (0);
		else if (index.check == 1)
			return (1);
		index.j++;
	}
	index.j--;
	if (line2[index.j] == '1' && (line2[index.j] == line1[index.j]
	|| line2[index.j] == line1[index.j - 1]
	|| line2[index.j] == line1[index.j + 1]))
		return (1);
	return (0);
}

int		ft_check_last_line(char *line1, char *line2)
{
	int	i;

	i = 0;
	while (line2[i])
	{
		if (line2[i] == ' ' && (line1[i] != '1' && line1[i - 1] != '1'
		&& line1[i + 1] != '1'))
			return (0);
		if (line2[i] != '1' && line2[i] != ' ' && line1[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_parse_line(parse_t *parse, char *buf, char **line, char **rd_line)
{
	get_next_line(parse, buf, line);
	*rd_line = ft_strdup(*line);
	free(*line);
	*line = NULL;
	printf("line		= %s\n", *rd_line);
}

void	ft_init_next_line(char **line2, char **line1)
{
	free(*line1);
	*line1 = NULL;
	*line1 = ft_strdup(*line2);
}

int		ft_parse_map(char *buf, parse_t *parse)
{
	static char	*line1 = NULL;
	static char	*line2 = NULL;
	char		*line;
	int			i;

	i = 0;
	line = 0;
	while (buf[parse->i] != '1')
		parse->i++;
	while (buf[parse->i - 1] != '\n')
		parse->i--;
	ft_parse_line(parse, buf, &line, &line1);
	while (buf[parse->i])
	{
		if (line2 != NULL)
			ft_init_next_line(&line2, &line1);
		ft_parse_line(parse, buf, &line, &line2);
		if (ft_check_line(line1, line2) == 0)
			return (0);
	}
	if (ft_check_last_line(line1, line2) == 0)
		return (0);
	return (1);
}
