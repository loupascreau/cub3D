/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:30:53 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/28 15:08:59 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_set_params(parse_t *parse, cast_t *cast)
{
	cast->map_width = parse->longest;
	cast->map_height = parse->height;
	cast->screen_width = parse->x;
	cast->screen_height = parse->y;
	cast->dirX = parse->dirX;
	cast->dirY = parse->dirY;
	cast->posX = parse->posX;
	cast->posY = parse->posY;
	cast->planeX = 0;
	cast->planeY = 0.66;
	cast->time = 0;
	cast->old_time = 0;
}

void	ft_setup_data_parse_cast(parse_t *parse, cast_t *cast)
{
	int	j;
	int i;

	j = 0;
	ft_set_params(parse, cast);
	printf("dirX = %f, dirY = %f\n", cast->dirX, cast->dirY);
	printf("posX = %f, posY = %f\n", cast->posX, cast->posY);
	if (!(cast->map = (int **)malloc(sizeof(int *) * cast->map_height + 1)))
		return ;
	while (parse->tab[j])
	{
		i = 0;
		if (!(cast->map[j] = (int *)malloc(sizeof(int) * cast->map_width + 1)))
			return ;
		while (parse->tab[j][i])
		{
			cast->map[j][i] = parse->tab[j][i] - 48;
			printf("%d", cast->map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}
