/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:23:26 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/20 19:25:57 by lpascrea         ###   ########.fr       */
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

typedef struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_tex
{
	void			*img;
	char			*addr;
	int				bits_per_pixels;
	int				size_line;
	int				endian;
}					t_tex;

typedef struct		s_save
{
	char			b;
	char			m;
	int				size_file;
	int				offset;
	int				size_img_header;
	int				img_width;
	int				img_height;
	short			plane;
	short			bpp;
	int				size_img;
	int				fd;
}					t_save;

typedef struct		s_cast
{
	int				map_width;
	int				map_height;
	int				screen_width;
	int				screen_height;
	int				**map;
	double			dirx;
	double			diry;
	double			posx;
	double			posy;
	double			planex;
	double			planey;
	double			camerax;
	double			ray_dirx;
	double			ray_diry;
	int				mapx;
	int				mapy;
	double			side_distx;
	double			side_disty;
	double			delta_distx;
	double			delta_disty;
	double			perp_wall_dist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	unsigned int	color;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixels;
	int				size_line;
	int				endian;
	int				x;
	int				floor;
	int				ceil;
	double			old_dirx;
	double			old_planex;
	double			pi;
	int				sizex;
	int				sizey;
	int				tex_width;
	int				tex_height;
	int				xcolor;
	int				ycolor;
	int				xycolor;
	int				tex_num;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			tex_pos;
	t_tex			*tex;
	double			*buffer;
	t_sprite		sprite[100];
	int				nbr_sprite;
	double			spritex;
	double			spritey;
	double			inv_det;
	double			transformx;
	double			transformy;
	int				sprite_screenx;
	int				sprite_height;
	int				sprite_width;
	int				draw_startx;
	int				draw_starty;
	int				draw_endx;
	int				draw_endy;
	int				stripe;
	int				save;
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rot_left;
	int				rot_right;
	int				echap;
	int				close;
}					t_cast;

typedef struct		s_parse
{
	int				fd;
	int				last;
	int				reso;
	int				x;
	int				y;
	int				i;
	int				north;
	char			*no;
	int				south;
	char			*so;
	int				west;
	char			*we;
	int				east;
	char			*ea;
	int				sprite;
	char			*s;
	int				floor;
	char			*f;
	int				ceil;
	char			*c;
	char			**tab;
	int				posx;
	int				posy;
	int				longest;
	int				height;
	int				dirx;
	int				diry;
	int				letter;
	double			planex;
	double			planey;
}					t_parse;

int					ft_atoi(char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strcpy(char *dest, char *src);
char				*ft_putnbr_base(int nbr, char *tab, int i);
int					ft_strlen(char *str);
char				**ft_split(char const *s, char c, int *count);
int					ft_pos_base(char c, char *base);
int					ft_atoi_base(char *nbr, char *base);
int					ft_check_base(char *base);
char				*ft_putnbr_in_base(int nbr, char *base, char *final, int i);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
int					ft_check_argv(char *argv);
void				ft_init(t_parse *parse);
int					ft_list_params_textures(char *buf, t_parse *parse);
int					ft_list_params_colors_xy(char *buf, t_parse *parse);
int					ft_fill_ea(char *buf, t_parse *parse);
int					ft_fill_we(char *buf, t_parse *parse);
int					ft_fill_so(char *buf, t_parse *parse);
int					ft_fill_no(char *buf, t_parse *parse);
int					ft_fill_x_y(char *buf, t_parse *parse);
int					ft_fill_s(char *buf, t_parse *parse);
int					ft_fill_f(char *buf, t_parse *parse);
int					ft_fill_c(char *buf, t_parse *parse);
void				ft_fill_fc(char **str, char ***tmp2);
int					ft_is_nbr(char *s1);
void				ft_free(char *line, char **tmp);
void				ft_free_map(t_cast *cast);
void				ft_free_parse(t_parse *parse);
int					ft_read_map(t_parse *parse);
int					ft_find_player(t_parse *parse);
void				ft_set_direction(t_parse *parse, char c);
void				ft_last(t_parse *parse);
int					ft_map_at_end(char *buf, t_parse *parse);
int					ft_count_line(char *buf, t_parse *parse, char ***tab);
char				*ft_count_nbr(char **line, char *tab, t_parse *parse);
void				ft_fill_empty(char **tab, t_parse *parse);
int					ft_parse_map(char *buf, t_parse *parse);
int					ft_check_value(char c, int *letter);
int					ft_check_map(char **tab, int *letter, t_parse *parse);
int					get_next_line(t_parse *parse, char *buf, char **line);
char				*ft_strdup(char *s);
char				*ft_strjoin(char *s1, char *s2);
int					ft_line_found(char *tab);
int					ft_fill_line(char **tab, char **line, int var,
					t_parse *parse);
int					ft_check_all(char **tab, char **line, t_parse *parse,
					char *buf);
int					ft_engine(t_parse *parse, t_cast *cast);
int					ft_recup_sprites(t_parse *parse, t_cast *cast);
int					ft_setup_data_parse_cast(t_parse *parse, t_cast *cast);
void				ft_set_params(t_parse *parse, t_cast *cast);
int					ft_raycasting(t_cast *cast);
int					ft_save(t_cast *cast, t_parse *parse);
int					ft_init_texture(t_cast *cast, t_tex *tex, int w, t_parse *parse);
void				ft_init_data_texture(t_tex *tex);
void				ft_textures(t_cast *cast);
void				ft_texture_ns(t_cast *cast, t_tex *tex);
void				ft_texture_ew(t_cast *cast, t_tex *tex);
void				ft_sprite(t_cast *cast);
void				my_mlx_pixel_put(t_cast *cast);
void				ft_init_move(t_cast *cast);
void				ft_manage_keys(t_cast *cast);
int					ft_key_hook(int key, t_cast *cast);
int					ft_key_release(int key, t_cast *cast);
int					ft_close_window(t_cast *cast);
int					ft_expose(t_cast *cast);
int					ft_error(int nbr);
int					ft_error_parsing(int nbr);

#endif
