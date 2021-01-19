/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:38:06 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/16 10:34:10 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

void	ft_fill_F(char *buf, parse_t *parse)
{
	int		nbr1;
	int		nbr2;
	int		nbr3;

	parse->F = 1;
	parse->i++;
	nbr1 = ft_atoi(buf, parse);
	parse->i++;
	nbr2 = ft_atoi(buf, parse);
	parse->i++;
	nbr3 = ft_atoi(buf, parse);
	if (!(parse->f = (char *)malloc(sizeof(char) * (8 + 1))))
		return ;
	parse->f[0] = '0';
	parse->f[1] = 'x';
	parse->f = ft_putnbr_base(nbr1, parse->f, 4 - 1); 
	parse->f = ft_putnbr_base(nbr2, parse->f, 6 - 1); 
	parse->f = ft_putnbr_base(nbr3, parse->f, 8 - 1); 
	parse->f[8] = '\0';
	ft_last(parse);
	parse->i = 0;
}

void	ft_fill_C(char *buf, parse_t *parse)
{
	int		nbr1;
	int		nbr2;
	int		nbr3;

	parse->C = 1;
	parse->i++;
	nbr1 = ft_atoi(buf, parse);
	parse->i++;
	nbr2 = ft_atoi(buf, parse);
	parse->i++;
	nbr3 = ft_atoi(buf, parse);
	if (!(parse->c = (char *)malloc(sizeof(char) * (8 + 1))))
		return ;
	parse->c[0] = '0';
	parse->c[1] = 'x';
	parse->c = ft_putnbr_base(nbr1, parse->c, 4 - 1); 
	parse->c = ft_putnbr_base(nbr2, parse->c, 6 - 1); 
	parse->c = ft_putnbr_base(nbr3, parse->c, 8 - 1); 
	parse->c[8] = '\0';
	ft_last(parse);
	parse->i = 0;
}

void	ft_last(parse_t *parse)
{
	if (parse->i > parse->last)
		parse->last = parse->i;
}
