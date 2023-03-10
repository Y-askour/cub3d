/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:25:12 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/23 00:41:22 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_BONUS_H
# define INCLUDE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../utils/libft/libft.h"

// Keycodes for mlx
# define DESTROY 17
# define KEY_RELEASE 3
# define KEY_PRESS 2
# define MOUSEMOVE 6

//

// Keycodes for Mac
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define ROTATE_LEFT 123
# define ROTATE_UP 126
# define ROTATE_DOWN 125
# define ROTATE_RIGHT 124
# define INT_MAX 2147483647

// The above code is defining the size of the window
# define CUB 10
//

typedef struct s_parss
{
	char			**all;
	char			**map;

	char			*ceiling;
	char			*floor;

	char			*west;
	char			*east;
	char			*south;
	char			*north;

	int				w_index;
	int				e_index;
	int				s_index;
	int				n_index;

	int				c_index;
	int				f_index;

	int				map_index;
}					t_parss;

typedef struct s_valid_data
{
	unsigned int	ceiling[3];
	unsigned int	floor[3];
	char			*so;
	char			*no;
	char			*ea;
	char			*we;
	char			**maps;
	int				map_len;
	int				line_len;
	char			player;
}					t_valid_data;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				w_win;
	int				h_win;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_mlx;
typedef struct s_key
{
	int				x;
	int				y;
	int				pov;
}					t_key;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_texture;

typedef struct s_norm
{
	double			first_x;
	double			first_y;
	double			step_x;
	double			step_y;
	double			cub_distance;
	double			wall_height;
	int				start;
	int				end;
	unsigned int	color;
	t_texture		*choice_txt;
	double			start_angle;
}	t_norm;

typedef struct s_all
{
	t_parss			parss;
	t_valid_data	valid;
	t_mlx			mlx;
	t_key			key;
	unsigned int	len;
	double			x_player;
	double			y_player;
	double			direction_ang;
	double			rotation_speed;
	double			horizontal_distance;
	double			verticale_distance;
	double			ver_x;
	double			ver_y;
	double			hor_x;
	double			hor_y;
	int				new_pov;
	double			x_offset;
	t_texture		w_txt;
	t_texture		e_txt;
	t_texture		n_txt;
	t_texture		s_txt;
	t_texture		gun_1_txt;
	t_texture		gun_2_txt;
	t_texture		gun_3_txt;
	t_texture		minimap;
	int				shot_;
	t_norm			norm;
	t_texture		*gun_frame;
	int				y_p_pos;
	int				x_p_pos;
}					t_all;

// mlx_utils
void				init_mlx(t_all *data);
int					mlx_close(t_all *data);
int					mlx_key_release(int keycode, t_all *data);
int					mlx_key(int keycode, t_all *data);
int					mlx_keypress(t_all *data);
int					mouse_move(int x, int y, t_all *data);
void				my_mlx_pixel_put(t_all *data, int x, int y, int color);
void				run(t_all *data);
// list of functions that are used to move the player around the map.
void				move_up(t_all *data);
void				move_down(t_all *data);
void				move_left(t_all *data);
void				move_right(t_all *data);
void				rotate_left_and_right(t_all *data, int direction);

// parssing
int					parssing(char *av, t_all *data);

// parssing utils
void				init_data(t_all *data);
int					check_file_name(char *av);
int					read_file(char *file, t_all *data, int i);

// free
void				free_metadata(t_all *data);
void				free_all(t_all *data);
void				free_rgb(char **rgb);
void				free_textures(t_all *data);
void				free_map(t_all *data);
void				free_parssing(t_all *data);
void				free_maps(t_all *data);

// get_textures
int					get_west(t_all *data);
int					get_east(t_all *data);
int					get_south(t_all *data);
int					get_north(t_all *data);

// get_colors
int					get_floor(t_all *data);
int					get_ceiling(t_all *data);

// get_all
int					get_metadata(t_all *data);
void				get_map(t_all *data, int i, int len, int temp);

// check colors
int					check_ceiling(t_all *data, int j);
int					check_colors(t_all *data);

// check_colors_utils
int					cout_comma(char *str);
int					check_is_rgb(char **rgb);
int					fill_ceiling(char **color, t_all *data);
int					fill_floor(char **color, t_all *data);

// check_textures
int					check_textures(t_all *data);

// check_textures_utils
int					open_file(char *str);
void				init_textures(t_all *data);

// check_map
int					check_is_white_spaces(char *str);
int					check_map(t_all *data);
int					middle_char_helper1(t_all *data, int i, int j);
int					middle_char_helper2(t_all *data, int i, int j);
void				middle_char_helper3(t_all *data, int *start, \
					int *end, int *i);
unsigned int		big_len(t_all *data);
void				init_map(t_all *data);
int					check_characters(t_all *data);
int					first_and_last_char(char **str, int map_len, int line_len);
int					search(char *src, char *str);
int					endmap_index(char **str);
void				init_angle(t_all *data);
int					check_valid_map(t_all *data);
int					check_player(t_all *data, int i, int j, int player);
int					middle_char(t_all *data);
int					middle_char_helper(t_all *data, int i, int j);
void				add_space(t_all *data);
int					is_empty(char *str);
int					check_wall(t_all *data, double y, double x);

// drawing
int					draw(t_all *data);
void				player_position(t_all *data, int x, int y, int *player);
void				init_mlx(t_all *data);
double				normalize_angle(double ang);
double				calculate_distance(t_all *data, double y, double x);
void				vertical_inter(t_all *data, double ang);
void				vertical_inter_helper(t_all *data, \
					double ang, int *index_y, int *index_x);
void				vertical_inter_init(t_all *data, double ang);
void				horizontal_inter(t_all *data, double ang);
void				horizontal_inter_helper(t_all *data, double ang, \
					int *index_x, int *index_y);
void				horizontal_inter_init(t_all *data, double ang);
void				draw_rays_helper(t_all *data, double *x1, double *y1);
void				draw_rays_helper1(t_all *data, int i);
void				draw_rays_helper2(t_all *data, double *increment);
int					is_left(double ang);
int					is_up(double ang);
unsigned int		get_color(t_texture txt, double y, t_all *data, \
					double wall_height);
unsigned int		get_floor_c(t_all *data);
unsigned int		get_ceiling_c(t_all *data);

// minimap drawing
void				render_minimap(t_all *data);
void				draw_circle(t_all *data, double y, double x, int color);
void				draw_miniplayer(t_all *data, double x, double y, int color);

#endif
