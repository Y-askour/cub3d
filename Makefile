CC=cc
NAME=Cub3d
FLAGS=-Wall -Wextra -Werror
HEADER=include/include.h
SRC=$(addprefix src/,main.c parssing/parssing.c parssing/get_colors.c \
		parssing/get_all.c parssing/get_textures.c parssing/parssing_utils.c\
		free/free.c check/check_colors.c check/check_colors_utils.c)
SRC_OBJ=$(SRC:.c=.o)

GNL_SRC=$(addprefix utils/get_next_line/,get_next_line.c get_next_line_utils.c)
GNL_OBJ=$(GNL_SRC:.c=.o)
GNl_HEADER=utils/get_next_line/get_next_line.h

LIBFT_HEADER=utils/libft/libft.h

All:$(NAME)

$(NAME):utils/libft/libft.a $(GNL_OBJ) $(SRC_OBJ)
	$(CC) $(FLAGS) $(SRC_OBJ) $(GNL_OBJ) utils/libft/libft.a -o $(NAME)

utils/libft/libft.a:$(LIBFT_HEADER)
	make -C utils/libft/


/utils/get_next_line/%.o:/utils/get_next_line/%.c $(GNL_HEADER)
	$(CC) $(FlAGS) -c $< -o $@

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@


clean:
	rm -rf $(SRC_OBJ)
	rm -rf $(GNL_OBJ)
	make fclean -C utils/libft

fclean:clean
	rm -rf $(NAME)

re:fclean $(NAME)

.PHONY:get_next_line all fclean clean
