/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:50:14 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/28 19:08:20 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_key_hook(int key, cast_t *cast)
{
	if (key == 119)
	{
		if (cast->map[(int)cast->posY][(int)(cast->posX + cast->dirX)] == 0)
			cast->posX += cast->dirX;
		if (cast->map[(int)(cast->posY + cast->dirY)][(int)cast->posX] == 0)
			cast->posY += cast->dirY;
		printf("posX = %f, posY = %f\n", cast->posX, cast->posY);
	}
	return (0);
}
