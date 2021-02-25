/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:21:04 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/25 14:31:43 by lpascrea         ###   ########.fr       */
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
