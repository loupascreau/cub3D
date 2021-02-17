/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:48:05 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/17 11:31:44 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	my_mlx_pixel_put(t_cast *cast)
{
	int		i;

	i = 0;
	while (i < cast->screen_width * (cast->screen_height / 2))
		*(int *)&cast->addr[i++ * (cast->bits_per_pixels / 8)] = cast->ceil;
	while (i < cast->screen_width * cast->screen_height)
		*(int *)&cast->addr[i++ * (cast->bits_per_pixels / 8)] = cast->floor;
}
