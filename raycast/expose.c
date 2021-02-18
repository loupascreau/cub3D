/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:49:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/18 17:20:31 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_expose(t_cast *cast)
{
	my_mlx_pixel_put(cast);	
	if (ft_raycasting(cast) == 0)
		return (0);
	ft_sprite(cast);
	free(cast->buffer);
	//ft_manage_keys(cast);
	mlx_put_image_to_window(cast->mlx, cast->win, cast->img, 0, 0);
	return (1);
}
