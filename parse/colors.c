/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:38:06 by lpascrea          #+#    #+#             */
/*   Updated: 2021/03/01 16:47:28 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_last(t_parse *parse)
{
	if (parse->i > parse->last)
		parse->last = parse->i;
}

int		ft_fill_fc(char **str, char ***tmp2)
{
	int nbr0;
	int nbr1;
	int nbr2;

	nbr0 = ft_atoi((*tmp2)[0]);
	nbr1 = ft_atoi((*tmp2)[1]);
	nbr2 = ft_atoi((*tmp2)[2]);
	if (nbr0 > 255 || nbr1 > 255 || nbr2 > 255)
		return (0);
	*str = ft_putnbr_base(nbr0, *str, 2 - 1);
	*str = ft_putnbr_base(nbr1, *str, 4 - 1);
	*str = ft_putnbr_base(nbr2, *str, 6 - 1);
	(*str)[6] = '\0';
	free((*tmp2)[0]);
	free((*tmp2)[1]);
	free((*tmp2)[2]);
	*str = ft_convert_base(*str, "0123456789ABCDEF", "0123456789");
	return (1);
}

int		ft_fill_s(char *buf, t_parse *parse)
{
	char	*line;
	char	**tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	parse->sprite = parse->i;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ', &count);
	if (count != 2)
		return (ft_exit_sprite(parse, line, tmp, count));
	parse->s = ft_strdup(tmp[1]);
	parse->i += ft_strlen(line);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	free(line);
	ft_last(parse);
	parse->i = 0;
	return (1);
}

int		ft_fill_f(char *buf, t_parse *parse)
{
	char	*line;
	char	**tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	parse->floor = parse->i;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i + 1, i - 1);
	parse->i += i;
	tmp = ft_split(line, ',', &count);
	if (count != 3 || ft_is_nbr(tmp[0]) == 0 ||
	ft_is_nbr(tmp[1]) == 0 || ft_is_nbr(tmp[2]) == 0)
		return (ft_exit_floor(parse, line, tmp, count));
	if (!(parse->f = (char *)malloc(sizeof(char) * (6 + 1))))
		return (0);
	free(line);
	if (ft_fill_fc(&parse->f, &tmp) == 0)
		return (ft_exit_cf(parse, tmp, count));
	free(tmp);
	ft_last(parse);
	parse->i = 0;
	return (1);
}

int		ft_fill_c(char *buf, t_parse *parse)
{
	char	*line;
	char	**tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	parse->ceil = parse->i;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i + 1, i - 1);
	parse->i += i;
	tmp = ft_split(line, ',', &count);
	if (count != 3 || ft_is_nbr(tmp[0]) == 0 ||
	ft_is_nbr(tmp[1]) == 0 || ft_is_nbr(tmp[2]) == 0)
		return (ft_exit_ceil(parse, line, tmp, count));
	if (!(parse->c = (char *)malloc(sizeof(char) * (6 + 1))))
		return (0);
	free(line);
	if (ft_fill_fc(&parse->c, &tmp) == 0)
		return (ft_exit_cf(parse, tmp, count));
	free(tmp);
	ft_last(parse);
	parse->i = 0;
	return (1);
}
