/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:46:45 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/13 13:45:03 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

void	ft_fill_x_y(char *buf, data_t *data)
{
	int		i;

	data->x = ft_atoi(buf, data);
	i = data->i;
	data->y = ft_atoi(&buf[i + 1], data);
}

int		ft_read_map(data_t *data)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;
	int		i;

	i = 0;
	if ((ret = read(data->fd, buf, BUFFER_SIZE)) <= 0)
	{
		printf("Error lecture ou fichier trop petit\n");
		return (0);
	}
	buf[ret] = '\0';
	while (i < ret)
	{
		if (buf[i] == 'R')
			ft_fill_x_y(&buf[i + 1], data);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	data_t	data;

	(void)argv;
	if (argc != 2)
	{
		printf("nombre darguments Error\n");
		return (0);
	}
	data.fd = open(argv[1], O_RDONLY);
	if (ft_read_map(&data) == 0)
		return (0);
	return (0);
}
