/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:57:55 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/17 15:46:23 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_init_move(t_move *move)
{
	move->forward = 0;
	move->back = 0;
	move->left = 0;
	move->right = 0;
	move->rot_left = 0;
	move->rot_right = 0;
	move->echap = 0;
	move->close = 0;
}

void	ft_move_keys(t_move *move, t_cast *cast)
{
	ft_init_move(move);
	if (move->forward == 1)
	{
		if (cast->map[(int)cast->posy][(int)(cast->posx + cast->dirx)] == 0)
		cast->posx += cast->dirx;
		if (cast->map[(int)(cast->posy + cast->diry)][(int)cast->posx] == 0)
		cast->posy += cast->diry;
	}
}
