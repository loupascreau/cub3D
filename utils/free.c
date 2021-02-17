/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:21:56 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/17 13:47:03 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_free(char *line, char **tmp)
{
	free(line);
	line = NULL;
	free(tmp);
	tmp = NULL;
}

void	ft_free_map(t_cast *cast)
{
	int i;

	i = 0;
	while (i < cast->map_height)
	{
		free(cast->map[i]);
		i++;
	}
	free(cast->map);
}

void	ft_free_parse(t_parse *parse)
{
	free(parse->no);
	free(parse->so);
	free(parse->ea);
	free(parse->we);
	free(parse->s);
}
