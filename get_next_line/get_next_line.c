/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:14:44 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/22 15:49:10 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_line_found(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		ft_fill_line(char **tab, char **line, int var, parse_t *parse)
{
	char	*tmp;
	int		size_tab;

	parse->i += var + 1;
	size_tab = ft_strlen(*tab + var + 1);
	*line = ft_substr(*tab, 0, var);
	if (size_tab == 0)
	{
		free(*tab);
		*tab = NULL;
		return (1);
	}
	tmp = ft_substr(*tab, var + 1, size_tab);
	free(*tab);
	*tab = tmp;
	return (1);
}

int		ft_check_all(char **tab, char **line, parse_t *parse, char *buf)
{
	int		var;

	if (buf[parse->i] == '\0')
		return (-1);
	if (*tab && (var = ft_line_found(*tab)) >= 0)
		return (ft_fill_line(tab, line, var, parse));
	else if (*tab)
	{
		*line = ft_strdup(*tab);
		free(*tab);
		*tab = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(parse_t *parse, char *buf, char **line)
{
	static char	*tab = 0;
	int			var;

	if (!line)
		return (-1);
	if (tab == 0)
	{
		tab = ft_strdup("");
		tab = ft_strjoin(tab, &buf[parse->i]);
	}
	if ((var = ft_line_found(tab)) >= 0)
		return (ft_fill_line(&tab, line, var, parse));
	return (ft_check_all(&tab, line, parse, buf));
}
