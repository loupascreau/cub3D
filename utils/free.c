/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:21:56 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/10 12:27:20 by lpascrea         ###   ########.fr       */
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

void	ft_free_map(cast_t *cast)
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
