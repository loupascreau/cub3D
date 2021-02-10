/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:48:05 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/10 15:51:13 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	my_mlx_pixel_put(cast_t *cast)
{
	int		i;

	i = 0;
	while (i < cast->screen_width * (cast->screen_height / 2))
		*(int *)&cast->addr[i++ * (cast->bits_per_pixels / 8)] = cast->ceil;
	while (i < cast->screen_width * cast->screen_height)
		*(int *)&cast->addr[i++ * (cast->bits_per_pixels / 8)] = cast->floor;
}

void	my_mlx_pixel_put2(cast_t *cast, int draw_start, int draw_end, int color)
{
	char	*dst;

	while (draw_start < draw_end)
	{
		dst = &cast->addr[(draw_start * cast->size_line) + (cast->x * (cast->bits_per_pixels / 8))];
		*(unsigned int*)dst = color;
		draw_start++;
	}
}
