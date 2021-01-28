/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:49:35 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/27 11:35:43 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_count_line(char *buf, parse_t *parse, char ***tab)
{
	int	j;
	int	i;
	int	len;

	i = 0;
	j = parse->i;
	len = 0;
	while (buf[j])
	{
		if (buf[j] == '\n')
		{
			i++;
			if (len > parse->longest)
				parse->longest = len;
			len = 0;
		}
		else
			len++;
		j++;
	}
	parse->height = i;
	if (!(*tab = (char **)malloc(sizeof(char *) * i + 1)))
		return ;
}

char	*ft_count_nbr(char **line, char *tab, parse_t *parse)
{
	int	size;
	int len;

	len = ft_strlen(*line);
	size = parse->longest;
	if (!(tab = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	tab[size] = '\0';
	tab = ft_strcpy(tab, *line);
	if (len < parse->longest)
	{
		while (len < size)
		{
			tab[len] = ' ';
			len++;
		}
	}
	free(*line);
	*line = NULL;
	return (tab);
}

void	ft_fill_empty(char *tab, parse_t *parse)
{
	int i;

	i = 0;
	while (i < parse->longest)
	{
		if (tab[i] == ' ')
		{
			tab[i] = '1';
			i++;
		}
		else
			i++;
	}
}

int		ft_parse_map(char *buf, parse_t *parse)
{
	char			*line;
	int				size;
	int				j;

	j = 0;
	line = 0;
	ft_count_line(buf, parse, &parse->tab);
	while (buf[parse->i])
	{
		size = 0;
		get_next_line(parse, buf, &line);
		if ((parse->tab[j] = ft_count_nbr(&line, parse->tab[j], parse)) == NULL)
			return (0);
		if (ft_check_map(parse->tab) == 0)
			return (0);
		ft_fill_empty(parse->tab[j], parse);
		j++;
	}
	return (1);
}
