#ifndef INCLUDE_H
#define INCLUDE_H
#include <stdio.h>
#include "../utils/libft/libft.h"
#include "../utils/get_next_line/get_next_line.h"
#include <fcntl.h>

typedef struct s_parss
{
  char **all;
  char **map;

  char *ceiling;
  char *floor;

  char *west;
  char *east;
  char *south;
  char *north;

  int w_index;
  int e_index;
  int s_index;
  int n_index;
  
  int c_index;
  int f_index;

  int map_index;
} t_parss;



typedef struct s_valid_data
{
  unsigned int ceiling[3];
  unsigned int floor[3];

} t_valid_data;

typedef struct s_all
{
  t_parss parss;
  t_valid_data valid;
  unsigned int len;
} t_all;

// parssing
int parssing(char *av,t_all *data);

// parssing utils
void init_data(t_all *data);
int check_file_name(char *av);
int read_file(char *file,t_all *data);

// free
void free_metadata(t_all *data);
void free_all(t_all *data);

// get_textures
int get_west(t_all *data);
int get_east(t_all *data);
int get_south(t_all *data);
int get_north(t_all *data);

// get_colors
int get_floor(t_all *data);
int get_ceiling(t_all *data);

// get_all
int get_metadata(t_all *data);
void get_map(t_all *data);

// check data
int check_ceiling(t_all *data);
#endif
