/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:57:55 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/18 17:20:12 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_init_move(t_cast *cast)
{
	cast->forward = 0;
	cast->back = 0;
	cast->left = 0;
	cast->right = 0;
	cast->rot_left = 0;
	cast->rot_right = 0;
	cast->echap = 0;
	cast->close = 0;
}

void	ft_manage_keys(t_cast *cast)
{
	(void)cast;
	/*if (move->forward == 1)
	{
		if (cast->map[(int)cast->posy][(int)(cast->posx + cast->dirx)] == 0)
		cast->posx += cast->dirx;
		if (cast->map[(int)(cast->posy + cast->diry)][(int)cast->posx] == 0)
		cast->posy += cast->diry;
	}*/
	printf("here\n");
}
