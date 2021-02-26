/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:21:04 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/26 10:44:21 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_exit_player_map(t_parse *parse)
{
	int	j;

	j = 0;
	while (j < parse->height)
	{
		free(parse->tab[j]);
		j++;
	}
	free(parse->tab);
	free(parse->no);
	free(parse->so);
	free(parse->ea);
	free(parse->we);
	free(parse->s);
	free(parse->f);
	free(parse->c);
	return (ft_error(3));
}

int		ft_exit_check_map(t_parse *parse)
{
	int	j;

	j = 0;
	while (j < parse->height)
	{
		free(parse->tab[j]);
		j++;
	}
	free(parse->tab);
	free(parse->no);
	free(parse->so);
	free(parse->ea);
	free(parse->we);
	free(parse->s);
	free(parse->f);
	free(parse->c);
	return (ft_error_parsing(10));
}

int		ft_exit_map_close(t_parse *parse)
{
	int	j;

	j = 0;
	while (j < parse->height)
	{
		free(parse->tab[j]);
		j++;
	}
	free(parse->tab);
	free(parse->no);
	free(parse->so);
	free(parse->ea);
	free(parse->we);
	free(parse->s);
	free(parse->f);
	free(parse->c);
	return (ft_error_parsing(8));
}

int		ft_exit_screen(t_parse *parse)
{
	int	j;

	j = 0;
	while (j < parse->height)
	{
		free(parse->tab[j]);
		j++;
	}
	free(parse->tab);
	free(parse->no);
	free(parse->so);
	free(parse->ea);
	free(parse->we);
	free(parse->s);
	free(parse->f);
	free(parse->c);
	return (ft_error_screen(0));
}

int		ft_exit_parse_file(t_parse *parse)
{
	if (parse->north == 1)
		free(parse->no);
	if (parse->east == 1)
		free(parse->ea);
	if (parse->south == 1)
		free(parse->so);
	if (parse->west == 1)
		free(parse->we);
	if (parse->sprite == 1)
		free(parse->s);
	if (parse->floor == 1)
		free(parse->f);
	if (parse->ceil == 1)
		free(parse->c);
	return (ft_error_parsing(9));
}
