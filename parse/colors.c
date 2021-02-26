/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:38:06 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/26 11:20:59 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_last(t_parse *parse)
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
	free((*tmp2)[0]);
	free((*tmp2)[1]);
	free((*tmp2)[2]);
	*str = ft_convert_base(*str, "0123456789ABCDEF", "0123456789");
}

int		ft_fill_s(char *buf, t_parse *parse)
{
	char	*line;
	char	**tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	parse->sprite = 1;
	while (buf[parse->i + i] != '\n')
		i++;
	line = ft_substr(buf, parse->i, i);
	tmp = ft_split(line, ' ', &count);
	if (count != 2)
		return (ft_exit_sprite(parse, line, tmp));
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
	parse->floor = 1;
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
	ft_fill_fc(&parse->f, &tmp);
	free(tmp);
	free(line);
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
	parse->ceil = 1;
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
	ft_fill_fc(&parse->c, &tmp);
	free(tmp);
	free(line);
	ft_last(parse);
	parse->i = 0;
	return (1);
}
