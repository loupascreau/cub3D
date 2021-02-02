/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:23:26 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/01 14:38:42 by lpascrea         ###   ########.fr       */
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
# include <math.h>
# include "../minilibx-linux/mlx.h"
# define BUFFER_SIZE 4096

typedef struct		cast_s
{
	int		map_width;
	int		map_height;
	int		screen_width;
	int		screen_height;
	int		**map;
	double	dirX;
	double	dirY;
	double	posX;
	double	posY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	ray_dirX;
	double	ray_dirY;
	int		mapX;
	int		mapY;
	double	side_distX;
	double	side_distY;
	double	delta_distX;
	double	delta_distY;
	double	perp_wall_dist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		size_line;
	int		endian;
	int		x;
	int		floor;
	int		ceil;
	double	old_dirX;
	double	old_planeX;
	double	pi;
	int		sizex;
	int		sizey;
	int		tex_width;
	int		tex_height;
}					cast_t;

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
	char	**tab;
	int		posX;
	int		posY;
	int		longest;
	int		height;
	int		dirX;
	int		dirY;
}					parse_t;

int		ft_atoi(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strcpy(char *dest, char *src);
char	*ft_putnbr_base(int nbr, char *tab, int i);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
int		ft_pos_base(char c, char *base);
int		ft_atoi_base(char *nbr, char *base);
int		ft_check_base(char *base);
char	*ft_putnbr_in_base(int nbr, char *base, char *final, int i);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_check_argv(char *argv);
void	ft_init(parse_t *parse);
int		ft_list_params_textures(char *buf, parse_t *parse);
int		ft_list_params_colors_xy(char *buf, parse_t *parse);
int		ft_fill_ea(char *buf, parse_t *parse);
int		ft_fill_we(char *buf, parse_t *parse);
int		ft_fill_so(char *buf, parse_t *parse);
int		ft_fill_no(char *buf, parse_t *parse);
int		ft_fill_x_y(char *buf, parse_t *parse);
int		ft_fill_s(char *buf, parse_t *parse);
int		ft_fill_f(char *buf, parse_t *parse);
int		ft_fill_c(char *buf, parse_t *parse);
void	ft_fill_fc(char **str, char ***tmp2);
void	ft_free(char *line, char **tmp);
int		ft_read_map(parse_t *parse);
int		ft_find_player(parse_t *parse);
void	ft_set_direction(parse_t *parse, char c);
void	ft_last(parse_t *parse);
int		ft_map_at_end(char *buf, parse_t *parse);
void	ft_count_line(char *buf, parse_t *parse, char ***tab);
char	*ft_count_nbr(char **line, char *tab, parse_t *parse);
void	ft_fill_empty(char *tab, parse_t *parse);
int		ft_parse_map(char *buf, parse_t *parse);
int		ft_check_map(char **tab);
int		get_next_line(parse_t *parse, char *buf, char **line);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_line_found(char *tab);
int		ft_fill_line(char **tab, char **line, int var, parse_t *parse);
int		ft_check_all(char **tab, char **line, parse_t *parse, char *buf);
void	ft_setup_data_parse_cast(parse_t *parse, cast_t *cast);
void	ft_set_params(parse_t *parse, cast_t *cast);
void	ft_raycasting(cast_t *cast);
void	my_mlx_pixel_put(cast_t *cast, int x, int draw_start, int draw_end, int color);
int		ft_key_hook(int key, cast_t *cast);
int		ft_pixel_put(cast_t *cast);

#endif
