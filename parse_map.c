/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:49:35 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/26 11:15:01 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

void	ft_count_line(char *buf, parse_t *parse, char ***tab)
{
	int	j;
	int	i;

	i = 0;
	j = parse->i;
	while (buf[j])
	{
		if (buf[j] == '\n')
			i++;
		j++;
	}
	if (!(*tab = (char **)malloc(sizeof(char *) * i + 1)))
		return ;
}

char	*ft_count_nbr(char **line, char *tab)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(*line);
	if (!(tab = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	tab[size] = '\0';
	tab = ft_strcpy(tab, *line);
	free(*line);
	*line = NULL;
	return (tab);
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
		if ((parse->tab[j] = ft_count_nbr(&line, parse->tab[j])) == NULL)
			return (0);
		if (ft_check_map(parse->tab) == 0)
			return (0);
		j++;
	}
	return (1);
}
