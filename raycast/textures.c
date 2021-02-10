/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:54:11 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/07 09:36:12 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_texture_ew(cast_t *cast, tex_t *tex)
{
	if (cast->ray_dirX >= 0)
	{
		while (cast->draw_start < cast->draw_end)
		{
			cast->texY = abs((((cast->draw_start * 256 - cast->screen_height * 128 + cast->line_height * 128) * 64) / cast->line_height) / 256);
			ft_memcpy(cast->addr + 4 * cast->screen_width * cast->draw_start + cast->x * 4, &tex[3].addr[cast->texY % 64 * tex[3].size_line + cast->texX % 64 * tex[3].bits_per_pixels / 8], sizeof(int));
			cast->draw_start++;
		}
	}
	else
	{
		while (cast->draw_start < cast->draw_end)
		{
			cast->texY = abs((((cast->draw_start * 256 - cast->screen_height * 128 + cast->line_height * 128) * 64) / cast->line_height) / 256);
			ft_memcpy(cast->addr + 4 * cast->screen_width * cast->draw_start + cast->x * 4, &tex[2].addr[cast->texY % 64 * tex[2].size_line + cast->texX % 64 * tex[2].bits_per_pixels / 8], sizeof(int));
			cast->draw_start++;
		}
	}

}

void	ft_texture_ns(cast_t *cast, tex_t *tex)
{
	if (cast->ray_dirY >= 0)
	{
		while (cast->draw_start < cast->draw_end)
		{
			cast->texY = abs((((cast->draw_start * 256 - cast->screen_height * 128 + cast->line_height * 128) * 64) / cast->line_height) / 256);
			ft_memcpy(cast->addr + 4 * cast->screen_width * cast->draw_start + cast->x * 4, &tex[1].addr[cast->texY % 64 * tex[1].size_line + cast->texX % 64 * tex[1].bits_per_pixels / 8], sizeof(int));
			cast->draw_start++;
		}
	}
	else
	{
		while (cast->draw_start < cast->draw_end)
		{
			cast->texY = abs((((cast->draw_start * 256 - cast->screen_height * 128 + cast->line_height * 128) * 64) / cast->line_height) / 256);
			ft_memcpy(cast->addr + 4 * cast->screen_width * cast->draw_start + cast->x * 4, &tex[0].addr[cast->texY % 64 * tex[0].size_line + cast->texX % 64 * tex[0].bits_per_pixels / 8], sizeof(int));
			cast->draw_start++;
		}
	}
}

void	ft_textures(cast_t *cast)
{
	cast->line_height = (int)(cast->screen_height / cast->perp_wall_dist);
	cast->draw_start = -cast->line_height / 2 + cast->screen_height / 2;
	if (cast->draw_start < 0)
		cast->draw_start = 0;
	cast->draw_end = cast->line_height / 2 + cast->screen_height / 2;
	if (cast->draw_end >= cast->screen_height)
		cast->draw_end = cast->screen_height - 1;
	if (cast->side == 0)
		cast->wallX = cast->posY + cast->perp_wall_dist * cast->ray_dirY;
	else
		cast->wallX = cast->posX + cast->perp_wall_dist * cast->ray_dirX;
	cast->wallX -= floor(cast->wallX);
	cast->texX = (int)(cast->wallX * (double)cast->tex_width);
	if (cast->side == 0 && cast->ray_dirX > 0)
		cast->texX = cast->tex_width - cast->texX - 1;
	if (cast->side == 1 && cast->ray_dirY < 0)
		cast->texX = cast->tex_width - cast->texX - 1;
	if (cast->side == 1)
		ft_texture_ns(cast, cast->tex);
	else
		ft_texture_ew(cast, cast->tex);
}
