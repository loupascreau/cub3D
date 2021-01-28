/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:48:05 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/28 12:09:49 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	my_mlx_pixel_put(data_t *data, int x, int draw_start, int draw_end, int color)
{
	char	*dst;
	
	while (draw_start < draw_end)
	{
		dst = &data->addr[(draw_start * data->size_line) + (x * (data->bits_per_pixels / 8))];
		*(unsigned int*)dst = color;
		draw_start++;
	}
}
