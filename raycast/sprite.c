/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:00:42 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/17 11:33:04 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_recup_sprites(t_parse *parse, t_cast *cast)
{
	int	i;
	int	j;
	int	n;

	j = 0;
	n = 0;
	while (j < parse->height)
	{
		i = 0;
		while (parse->tab[j][i])
		{
			if (parse->tab[j][i] == '2' && n < 100)
			{
				cast->sprite[n].x = i + 0.5;
				cast->sprite[n].y = j + 0.5;
				n++;
			}
			i++;
		}
		j++;
	}
	return (n);
}

void	ft_sort_sprite(int *sprite_order, double *sprite_dist, int nbr_sprite)
{
	int 	i;
	double	tmp_dist;
	int		tmp_order;

	i = 0;
	while (i < nbr_sprite - 1)
	{
		if (sprite_dist[i] < sprite_dist[i + 1])
		{
			tmp_dist = sprite_dist[i];
			sprite_dist[i] = sprite_dist[i + 1];
			sprite_dist[i + 1] = tmp_dist;
			tmp_order = sprite_order[i];
			sprite_order[i] = sprite_order[i + 1];
			sprite_order[i + 1] = tmp_order;
			i = -1;
		}
		i++;
	}
}

void	ft_sprite(t_cast *cast)
{
	int		i;
	int		y;
	int		d;
	int		sprite_order[cast->nbr_sprite];
	double	sprite_dist[cast->nbr_sprite];

	i = 0;
	while (i < cast->nbr_sprite)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((cast->posX - cast->sprite[i].x) * (cast->posX - cast->sprite[i].x)
		+ (cast->posY - cast->sprite[i].y) * (cast->posY - cast->sprite[i].y));
		i++;
	}
	ft_sort_sprite(sprite_order, sprite_dist, cast->nbr_sprite);
	i = 0;
	while (i < cast->nbr_sprite)
	{
		cast->spriteX = cast->sprite[sprite_order[i]].x - cast->posX;
		cast->spriteY = cast->sprite[sprite_order[i]].y - cast->posY;
		cast->inv_det = 1.0 / (cast->planeX * cast->dirY - cast->dirX * cast->planeY);
		cast->transformX = cast->inv_det * (cast->dirY * cast->spriteX - cast->dirX * cast->spriteY);
		cast->transformY = cast->inv_det * (-cast->planeY * cast->spriteX + cast->planeX * cast->spriteY);
		cast->sprite_screenX = (int)((cast->screen_width / 2) * (1 + cast->transformX / cast->transformY));
		cast->sprite_height = abs((int)(cast->screen_height / cast->transformY));
		cast->draw_startY = -cast->sprite_height / 2 + cast->screen_height / 2;
		if (cast->draw_startY < 0)
			cast->draw_startY = 0;
		cast->draw_endY = cast->sprite_height / 2 + cast->screen_height / 2;
		if (cast->draw_endY >= cast->screen_height)
			cast->draw_endY = cast->screen_height - 1;
		cast->sprite_width = abs((int)(cast->screen_height / cast->transformY));
		cast->draw_startX = -cast->sprite_width / 2 + cast->sprite_screenX;
		if (cast->draw_startX < 0)
			cast->draw_startX = 0;
		cast->draw_endX = cast->sprite_width / 2 + cast->sprite_screenX;
		if (cast->draw_endX >= cast->screen_width)
			cast->draw_endX = cast->screen_width - 1;
		cast->stripe = cast->draw_startX;
		while (cast->stripe < cast->draw_endX)
		{
			cast->texX = (int)(256 * (cast->stripe - (-cast->sprite_width / 2 + cast->sprite_screenX)) * cast->tex_width / cast->sprite_width) / 256;
			y = cast->draw_startY;
			if (cast->transformY > 0 && cast->stripe > 0 && cast->stripe < cast->screen_width && cast->transformY < cast->buffer[cast->stripe])
			{
				while (y < cast->draw_endY)
				{
					d = y * 256 - cast->screen_height * 128 + cast->sprite_height * 128;
					cast->texY = ((d * cast->tex_height) / cast->sprite_height) / 256;
					if (cast->tex[4].addr[cast->texY % 64 * cast->tex[4].size_line + cast->texX % 64 * cast->tex[4].bits_per_pixels / 8] != 0)
					{
						ft_memcpy(cast->addr + 4 * cast->screen_width * y + cast->stripe * 4, &cast->tex[4].addr[cast->texY % 64 * cast->tex[4].size_line + cast->texX % 64 * cast->tex[4].bits_per_pixels / 8], sizeof(int));
					}
					y++;
				}
			}
			cast->stripe++;
		}
		i++;
	}
}
