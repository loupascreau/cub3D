/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:38:06 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/03 11:48:10 by lpascrea         ###   ########.fr       */
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
	*str = ft_putnbr_base(ft_atoi((*tmp2)[0]), *str, 2 - 1);
	*str = ft_putnbr_base(ft_atoi((*tmp2)[1]), *str, 4 - 1);
	*str = ft_putnbr_base(ft_atoi((*tmp2)[2]), *str, 6 - 1);
	(*str)[6] = '\0';
	*str = ft_convert_base(*str, "0123456789ABCDEF", "0123456789");
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
		return (ft_error_parsing(7));
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
	int		i;

	i = 0;
	parse->F = 1;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i + 1, i - 1);
	tmp = ft_split(line, ',');
	if (tmp[3] || ft_is_nbr(tmp[0]) == 0 || ft_is_nbr(tmp[1]) == 0 || ft_is_nbr(tmp[2]) == 0)
		return (ft_error_parsing(6));
	if (!(parse->f = (char *)malloc(sizeof(char) * (6 + 1))))
		return (0);
	ft_fill_fc(&parse->f, &tmp);
	ft_free(line, tmp);
	ft_last(parse);
	parse->i = 0;
	return (1);
}

int		ft_fill_c(char *buf, parse_t *parse)
{
	char	*line;
	char	**tmp;
	int		i;

	i = 0;
	parse->C = 1;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i + 1, i - 1);
	tmp = ft_split(line, ',');
	if (tmp[3] || ft_is_nbr(tmp[0]) == 0 || ft_is_nbr(tmp[1]) == 0 || ft_is_nbr(tmp[2]) == 0)
		return (ft_error_parsing(5));
	if (!(parse->c = (char *)malloc(sizeof(char) * (6 + 1))))
		return (0);
	ft_fill_fc(&parse->c, &tmp);
	ft_free(line, tmp);
	ft_last(parse);
	parse->i = 0;
	return (1);
}
