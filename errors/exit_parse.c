/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:21:04 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/26 17:37:52 by lpascrea         ###   ########.fr       */
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

int		ft_exit_file(t_parse *parse)
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
	return (ft_error_file(0));
}

int		ft_exit_parse_file(t_parse *parse)
{
	if (parse->north >= 0)
		free(parse->no);
	if (parse->east >= 0)
		free(parse->ea);
	if (parse->south >= 0)
		free(parse->so);
	if (parse->west >= 0)
		free(parse->we);
	if (parse->sprite >= 0)
		free(parse->s);
	if (parse->floor >= 0)
		free(parse->f);
	if (parse->ceil >= 0)
		free(parse->c);
	return (ft_error_parsing(9));
}
