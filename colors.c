/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:38:06 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/26 11:13:53 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

void	ft_last(parse_t *parse)
{
	if (parse->i > parse->last)
		parse->last = parse->i;
}

void	ft_fill_s(char *buf, parse_t *parse)
{
	int	diff;

	diff = 0;
	parse->S = 1;
	parse->i++;
	while (buf[parse->i] && diff == 0)
	{
		if (buf[parse->i] == '.' && buf[parse->i + 1] == '/')
		{
			while (buf[parse->i] > 32 && buf[parse->i] < 127)
			{
				diff++;
				parse->i++;
			}
			parse->s = ft_substr(buf, (parse->i - diff), diff);
		}
		parse->i++;
	}
	ft_last(parse);
	parse->i = 0;
}

void	ft_fill_f(char *buf, parse_t *parse)
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

void	ft_fill_c(char *buf, parse_t *parse)
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
