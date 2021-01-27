/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:38:06 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/27 11:23:09 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_last(parse_t *parse)
{
	if (parse->i > parse->last)
		parse->last = parse->i;
}

void	ft_fill_fc(char **str, char ***tmp2)
{
	(*str)[0] = '0';
	(*str)[1] = 'x';
	*str = ft_putnbr_base(ft_atoi((*tmp2)[0]), *str, 4 - 1);
	*str = ft_putnbr_base(ft_atoi((*tmp2)[1]), *str, 6 - 1);
	*str = ft_putnbr_base(ft_atoi((*tmp2)[2]), *str, 8 - 1);
	(*str)[8] = '\0';
	free(*tmp2);
	tmp2 = NULL;
}

int		ft_fill_s(char *buf, parse_t *parse)
{
	char	*line;
	char	**tmp;
	int		i;

	i = 0;
	parse->S = 1;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ');
	if (tmp[2])
	{
		printf("Error\nProblem with line S\n");
		return (0);
	}
	parse->s = tmp[1];
	parse->i += ft_strlen(line);
	ft_free(line, tmp);
	ft_last(parse);
	parse->i = 0;
	return (1);
}

int		ft_fill_f(char *buf, parse_t *parse)
{
	char	*line;
	char	**tmp;
	char	**tmp2;
	int		i;

	i = 0;
	parse->F = 1;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ');
	if (tmp[2])
	{
		printf("Error\nProblem with line F\n");
		return (0);
	}
	tmp2 = ft_split(tmp[1], ',');
	if (!(parse->f = (char *)malloc(sizeof(char) * (8 + 1))))
		return (0);
	ft_fill_fc(&parse->f, &tmp2);
	ft_free(line, tmp);
	ft_last(parse);
	parse->i = 0;
	return (1);
}

int		ft_fill_c(char *buf, parse_t *parse)
{
	char	*line;
	char	**tmp;
	char	**tmp2;
	int		i;

	i = 0;
	parse->C = 1;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ');
	if (tmp[2])
	{
		printf("Error\nProblem with line C\n");
		return (0);
	}
	tmp2 = ft_split(tmp[1], ',');
	if (!(parse->c = (char *)malloc(sizeof(char) * (8 + 1))))
		return (0);
	ft_fill_fc(&parse->c, &tmp2);
	ft_free(line, tmp);
	ft_last(parse);
	parse->i = 0;
	return (1);
}
