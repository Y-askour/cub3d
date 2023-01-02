CC=cc
NAME=Cub3d
FLAGS=-Wall -Wextra -Werror -Imlx -g
HEADER=include/include.h
SRC=$(addprefix src/,main.c parssing/parssing.c parssing/get_colors.c \
		parssing/get_all.c parssing/get_textures.c parssing/parssing_utils.c\
		free/free.c check/check_colors.c check/check_colors_utils.c\
		check/check_textures.c check/check_textures_utils.c check/check_map.c\
		raycasting/draw.c )
SRC_OBJ=$(SRC:.c=.o)
LIBFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
GNL_SRC=$(addprefix utils/get_next_line/,get_next_line.c get_next_line_utils.c)
GNL_OBJ=$(GNL_SRC:.c=.o)
GNl_HEADER=utils/get_next_line/get_next_line.h
MLX_LIB = mlx/libmlx.a
LIBFT_HEADER=utils/libft/libft.h

All:$(NAME)

$(NAME):$(MLX_LIB) utils/libft/libft.a $(GNL_OBJ) $(SRC_OBJ) 
	$(CC) $(FLAGS) $(SRC_OBJ) $(GNL_OBJ) utils/libft/libft.a  $(LIBFLAGS) $(MLX_LIB) -o $(NAME)

utils/libft/libft.a:$(LIBFT_HEADER)
	make -C utils/libft/


/utils/get_next_line/%.o:/utils/get_next_line/%.c $(GNL_HEADER)
	$(CC) $(FlAGS) -c $< -o $@

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(MLX_LIB):
	make -C mlx 2> /dev/null

clean:
	rm -rf $(SRC_OBJ)
	rm -rf $(GNL_OBJ)
	make fclean -C utils/libft
	make clean -C mlx

fclean:clean
	rm -rf $(NAME)

re:fclean $(NAME)

.PHONY:get_next_line all fclean clean
