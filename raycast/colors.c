/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:13:53 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/07 10:25:22 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_colors(cast_t *cast)
{
	cast->line_height = (int)(cast->screen_height / cast->perp_wall_dist);
	cast->draw_start = -cast->line_height / 2 + cast->screen_height / 2;
	if (cast->draw_start < 0)
		cast->draw_start = 0;
	cast->draw_end = cast->line_height / 2 + cast->screen_height / 2;
	if (cast->draw_end >= cast->screen_height)
		cast->draw_end = cast->screen_height - 1;
	if (cast->side == 1)
	{
		if (cast->ray_dirY < 0)
			cast->color = 0xFF0000;
		else
			cast->color = 0x00FF00;
	}
	else							
	{
		if (cast->ray_dirX < 0)
			cast->color = 0x0000FF;
		else
			cast->color = 0xFFFF00;
	}
	my_mlx_pixel_put2(cast, cast->draw_start, cast->draw_end, cast->color);
}
