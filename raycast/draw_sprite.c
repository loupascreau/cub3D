/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:29:12 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/27 19:35:24 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_draw_sprite(t_cast *cast, int d, int y)
{
	cast->texx = (int)(256 * (cast->stripe - (-cast->sprite_width / 2
	+ cast->sprite_screenx)) * cast->tex_width / cast->sprite_width) / 256;
	y = cast->draw_starty;
	if (cast->transformy > 0 && cast->stripe > 0 && cast->stripe <
	cast->screen_width && cast->transformy < cast->buffer[cast->stripe])
	{
		while (y < cast->draw_endy)
		{
			d = y * 256 - cast->screen_height * 128 + cast->sprite_height * 128;
			cast->texy = ((d * cast->tex_height) / cast->sprite_height) / 256;
			if (cast->tex[4].addr[cast->texy % 64 * cast->tex[4].size_line +
			cast->texx % 64 * cast->tex[4].bits_per_pixels / 8] != 0)
			{
				ft_memcpy(cast->addr + 4 * cast->screen_width * y + cast->stripe
				* 4, &cast->tex[4].addr[cast->texy % 64 * cast->tex[4].size_line
				+ cast->texx % 64 * cast->tex[4].bits_per_pixels / 8], sizeof(int));
			}
			y++;
		}
	}
}
