/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:58 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/15 17:23:33 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../utils/libft/libft.h"
# include <fcntl.h>
# include <math.h>

// Keycodes for Mac
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define INT_MAX 2147483647
// 
# define CUB 10
# define FOV 60 * M_PI / 180
# define TILE_SIZE 32
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
	int x;
	int y;
	int pov;
}					t_key;

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
	double 			horizontal_distance;
	double 			verticale_distance;
	double 			ver_x;
	double 			ver_y;
	double 			hor_x;
	double 			hor_y;
}					t_all;




// mlx_utils
void				init_mlx(t_all *data);
int					mlx_close(void);
int					mlx_key_release(int keycode, t_all *data);
int					mlx_key(int keycode, t_all *data);
int					mlx_keypress(t_all *data);
 

// The above code is a list of functions that are used to move the player around the map.
void				move_up(t_all *data);
void				move_down(t_all *data);
void				move_left(t_all *data);
void				move_right(t_all *data);
void 				rotate_left_and_right(t_all *data, int direction);

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
int					check_ceiling(t_all *data);
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
int					check_map(t_all *data);
int					is_empty(char *str);
int					check_wall(t_all *data, double y, double x);

// drawing
int					draw(t_all *data);
void				player_position(t_all *data, int x, int y);
void				init_mlx(t_all *data);
double				normalize_angle(double ang);

#endif
