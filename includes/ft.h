/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:23:26 by lpascrea          #+#    #+#             */
/*   Updated: 2021/01/18 11:25:22 by lpascrea         ###   ########.fr       */
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
	int		last;
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
	char	*f;
	int		C;
	char	*c;
}					parse_t;

int		ft_atoi(char *str, parse_t *parse);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_putnbr_base(int nbr, char *tab, int i);
int		ft_strlen(char *str);
int		ft_check_argv(char *argv);
void	ft_init(parse_t *parse);
int		ft_read_map(parse_t *parse);
void	ft_fill_x_y(char *buf, parse_t *parse);
void	ft_fill_NO(char *buf, parse_t *parse);
void	ft_fill_SO(char *buf, parse_t *parse);
void	ft_fill_WE(char *buf, parse_t *parse);
void	ft_fill_EA(char *buf, parse_t *parse);
void	ft_fill_S(char *buf, parse_t *parse);
void	ft_fill_F(char *buf, parse_t *parse);
void	ft_fill_C(char *buf, parse_t *parse);
void	ft_last(parse_t *parse);
int		ft_only_map(char *buf, parse_t *parse);
int		ft_parse_map(char *buf, parse_t *parse);
int		ft_check_line(char *first_line, char *next_line, int *start);
int		get_next_line(parse_t *parse, char *buf, char **line);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_line_found(char *tab);
int		ft_fill_line(char **tab, char **line, int var, parse_t *parse);
int		ft_check_all(char **tab, char **line, parse_t *parse, char *buf);

#endif
