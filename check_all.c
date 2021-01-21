/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:15:14 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/21 10:56:33 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

void	ft_init_index(index_t *index)
{
	index->i = 0;
	index->j = 0;
	index->check = 0;
}

int		ft_begin_next_line(char *line1, char *line2, index_t *index)
{
	while (index->j < index->i && line2[index->j] == '1'
	&& line1[index->j] == ' ')
		(index->j)++;
	if (line2[index->j] == '0' && line1[index->j] != '1')
		return (0);
	return (1);
}

int		ft_verif_lines(char *line1, char *line2, index_t *index, int *st)
{
	if (*st == 0)
	{
		while (line1[index->i] == '1')
			(index->i)++;
		if (line1[index->i] == '0' && line2[index->i] != '1'
		&& line2[index->i - 1] != '1')
			return (0);
		*st = 1;
	}
	else
	{
		while (line1[index->i] != ' ' && line1[index->i])
			(index->i)++;
		if (line1[index->i] == ' ' && ((line2[index->i] == ' '
		&& line2[index->i - 1] != '1' && line2[index->i + 1] != '1')
		|| line2[index->i] == '0'))
			return (0);
	}
	(index->i)--;
	return (1);
}

int		ft_inside_next_line(char *line1, char *line2, index_t *index, int *st)
{
	if (ft_verif_lines(line1, line2, index, st) == 0)
		return (0);
	while ((line2[index->j] != ' ' && line2[index->j]) && index->j <= index->i)
		(index->j)++;
	if (line2[index->j] == ' ' && line1[index->j] != '1'
	&& (line1[index->j - 1] != '1' || line1[index->j + 1] != '1'))
		return (0);
	while (index->i > index->j && line2[index->j + 1] == ' ')
	{
		if (line1[index->i] != '1' && line2[index->i] != '1')
			return (0);
		(index->i)--;
	}
	if (line2[index->j] == ' ' && (line1[index->j] != '1'
	&& line1[index->j - 1] != '1' && line1[index->j + 1] != '1'))
		return (0);
	if (line2[index->j + 1] == '\0' && (line1[index->i] == line2[index->j]
	|| line1[index->i] == line2[index->j - 1]
	|| line1[index->i] == line2[index->j + 1]))
		return (1);
	return (2);
}

int		ft_check_all_line(char *line1, char *line2, index_t *index, int *st)
{
	int	find;
	int	check;

	find = 0;
	if (line2[index->j] == ' ' && (line1[index->j] != '1'
	&& line1[index->j - 1] != '1' && line1[index->j + 1] != '1') && find == 1)
		return (0);
	if (line2[index->j] == '1')
	{
		find = 1;
		if (ft_begin_next_line(line1, line2, index) == 0)
			return (0);
		if (line1[index->i] == line2[index->i]
		|| line1[index->i] == line2[index->i - 1]
		|| line1[index->i] == line2[index->i + 1])
		{
			check = ft_inside_next_line(line1, line2, index, st);
			if (check == 0)
				return (0);
			else if (check == 1)
				return (1);
		}
	}
	return (2);
}
