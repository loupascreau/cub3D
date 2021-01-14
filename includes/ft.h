/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:23:26 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/14 14:44:17 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# define BUFFER_SIZE 4096

typedef struct		data_s
{
	void	*mlx;
	void	*win;
}					data_t;

typedef struct		parse_s
{
	int		fd;
	int		R;
	int		x;
	int		y;
	int		i;
	int		NO;
	char	*no;
	int		SO;
	char	*so;
	int		WE;
	char	*we;
	int		EA;
	char	*ea;
	int		S;
	char	*s;
	int		F;
	int		C;
}					parse_t;

int		ft_atoi(char *str, parse_t *parse);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_init(parse_t *parse);
int		ft_read_map(parse_t *parse);
void	ft_fill_x_y(char *buf, parse_t *parse);
void	ft_fill_NO(char *buf, parse_t *parse);
void	ft_fill_SO(char *buf, parse_t *parse);
void	ft_fill_WE(char *buf, parse_t *parse);
void	ft_fill_EA(char *buf, parse_t *parse);
void	ft_fill_S(char *buf, parse_t *parse);

#endif
