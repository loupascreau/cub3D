/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:30:19 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/13 13:44:45 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_atoi(char *str, data_t *data)
{
	int sign;
	int result;

	data->i = 0;
	sign = 1;
	result = 0;
	while (str[data->i] == '\n' || str[data->i] == '\t' || str[data->i] == '\v'
	|| str[data->i] == '\f' || str[data->i] == '\r' || str[data->i] == ' ')
		data->i++;
	if (str[data->i] == '+' || str[data->i] == '-')
	{
		if (str[data->i] == '-')
			sign = -sign;
		data->i++;
	}
	while (str[data->i] >= '0' && str[data->i] <= '9')
	{
		result = result * 10 + (str[data->i] - 48);
		data->i++;
	}
	return (result * sign);
}
