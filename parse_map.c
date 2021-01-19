/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:49:35 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/19 11:24:05 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

int		ft_check_line(char *first_line, char *next_line, int *start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (first_line[i])
	{
		if (first_line[i] == '1')
		{
			while (next_line[j])
			{
				if (next_line[j] == '1')
				{
					while (j < i && next_line[j] == '1')
						j++;
					if (*start == 0)
					{
						while (first_line[i] == '1')
							i++;
						*start = 1;
					}
					else
					{
						while (first_line[i] != ' ' && first_line[i])
							i++;
					}
					i--;
					while ((next_line[j] != ' ' || next_line[j]) && j != i)
						j++;
					if (j == i && (first_line[i] == next_line[j] || first_line[i] == next_line[j - 1]
					|| first_line[i] == next_line[j + 1]))
						return (1);
				}
				j++;
			}
		}
		i++;
	}
	return (0);
}

int		ft_parse_map(char *buf, parse_t *parse)
{
	char	*first_line;
	char	*next_line = NULL;
	char	*line;
	int		start;
	int		i;

	i = 0;
	line = 0;
	start = 0;
	while (buf[parse->i] != '1')
		parse->i++;	
	while (buf[parse->i - 1] != '\n')
		parse->i--;
	get_next_line(parse, buf, &line);
	first_line = ft_strdup(line);
	free(line);
	line = NULL;
	printf("first_line	= %s\n", first_line);
	while (buf[parse->i])
	{
		if (next_line != NULL)
		{
			free(first_line);
			first_line = NULL;
			first_line = ft_strdup(next_line);
		}
		get_next_line(parse, buf, &line);
		next_line = ft_strdup(line);
		free(line);
		line = NULL;
		printf("next_line	= %s\n", next_line);
		if (ft_check_line(first_line, next_line, &start) == 0)
			return (0);
	}
	return (1);
}
