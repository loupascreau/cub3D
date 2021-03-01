/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:42:09 by lpascrea          #+#    #+#             */
/*   Updated: 2021/03/01 17:08:11 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_check_map_closed(char **tab, int i, int j, t_parse *parse)
{
	if (tab[j][i + 1] == '\0' || tab[j][i + 1] == ' '
	|| tab[j][i - 1] == ' ')
		return (0);
	if (tab[j - 1][i] == '\0' || tab[j - 1][i] == ' ')
		return (0);
	if ((j + 1 != parse->height) && (tab[j + 1][i] == '\0'
	|| tab[j - 1][i] == ' '))
		return (0);
	if (j + 1 == parse->height)
		return (0);
	return (1);
}

int		ft_check_value(char c, int *letter)
{
	if (c == '1' || c == '0' || c == ' ' || c == '2')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (*letter == 1)
			return (0);
		*letter = 1;
		return (1);
	}
	return (0);
}

int		ft_check_sprite(char **tab, int i, int j, t_parse *parse)
{
	if (j == 0)
		return (0);
	if (tab[j][i + 1] == '\0' || tab[j][i + 1] == ' '
	|| tab[j][i - 1] == ' ')
		return (0);
	if (tab[j - 1][i] == '\0' || tab[j - 1][i] == ' ')
		return (0);
	if ((j + 1 != parse->height) && (tab[j + 1][i] == '\0'
	|| tab[j - 1][i] == ' '))
		return (0);
	if (j + 1 == parse->height)
		return (0);
	return (1);
}

int		ft_check_02(char **tab, int i, int j, t_parse *parse)
{
	if (tab[j][i] == '0')
	{
		if (ft_check_map_closed(tab, i, j, parse) == 0)
			return (ft_exit_map_close(parse));
	}
	if (tab[j][i] == '2')
	{
		if (ft_check_sprite(tab, i, j, parse) == 0)
			return (ft_exit_map_close(parse));
	}
	return (1);
}

int		ft_check_map(char **tab, int *letter, t_parse *parse)
{
	int	j;
	int	i;

	j = 0;
	while (j < parse->height)
	{
		i = 0;
		while (tab[j][i])
		{
			if (ft_check_value(tab[j][i], letter) == 0)
				return (ft_exit_check_map(parse));
			if (i == 0 && tab[j][i] == '0')
				return (ft_exit_map_close(parse));
			if (ft_check_02(tab, i, j, parse) == 0)
				return (0);
			if (j > 0 && tab[j][i] == ' ' && tab[j - 1][i] == '0')
				return (ft_exit_map_close(parse));
			i++;
		}
		j++;
	}
	return (1);
}
