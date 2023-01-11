#-------------------- Define Color -------------------#

R	= "\033[1;31m"
G	= "\033[1;32m"
Y	= "\033[1;33m"
B	= "\033[1;34m"
C	= "\033[0;36m"
P	= "\033[0;35m"
RS	= "\033[0m"

#------------------- End Define Color ------------------#

#          ----------========== {     VARS     } ==========----------
CC = cc
NAME = Cub3d
HEADER = include/include.h
FLAGS = -Wall -Wextra -Werror -Imlx
LIBFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_LIB = mlx/libmlx.a
GET_NEXT_LINE = /utils/get_next_line/
LIBFT_LIB = utils/libft/libft.a
LIBFT_HEADER = utils/libft/libft.h
GNl_HEADER = utils/get_next_line/get_next_line.h

#          ----------========== {     SRCS     } ==========----------


SRC = $(addprefix src/,main.c parssing/parssing.c parssing/get_colors.c \
		parssing/get_all.c parssing/get_textures.c parssing/parssing_utils.c\
		free/free.c check/check_colors.c check/check_colors_utils.c\
		check/check_textures.c check/check_textures_utils.c check/check_map.c\
		raycasting/draw.c )
SRC_OBJ = $(SRC:.c=.o)
GNL_SRC = $(addprefix utils/get_next_line/,get_next_line.c get_next_line_utils.c)
GNL_OBJ = $(GNL_SRC:.c=.o)

#          ----------========== {     RULES     } ==========----------
All:$(NAME)


$(NAME):$(MLX_LIB) $(LIBFT_LIB) $(GNL_OBJ) $(SRC_OBJ) 
	@echo "\n"
	@echo $(B)"         ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡ "$(RS)
	@echo $(B)"         ║"$(C)"░░░░░███████░░██░░░░██░░████████░░███████░░███████░░░░░░"$(B)"║"$(RS)
	@echo $(B)"         ║"$(C)"░░░░██░░░░░░░░██░░░░██░░██░░░░██░░░░░░░██░░██░░░░░██░░░░"$(B)"║"$(RS)
	@echo $(B)"         ║"$(C)"░░░░██░░░░░░░░██░░░░██░░███████░░░███████░░██░░░░░░██░░░"$(B)"║"$(RS)
	@echo $(B)"         ║"$(C)"░░░░██░░░░░░░░██░░░░██░░██░░░░██░░░░░░░██░░██░░░░░██░░░░"$(B)"║"$(RS)
	@echo $(B)"         ║"$(C)"░░░░░███████░░████████░░████████░░███████░░███████░░░░░░"$(B)"║"$(RS)
	@echo $(B)"         ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡ "$(RS)
	@echo "$                         "$(G)"_________Created_By__________"$(RS)
	@echo "                        "$(P)"    YOPI && Younes Askour"$(RS)
	@echo "$                         "$(G)"-----------------------------"$(RS)
	@echo "\n"
	@$(CC) $(FLAGS) $(SRC_OBJ) $(GNL_OBJ) $(LIBFT_LIB)  $(LIBFLAGS) $(MLX_LIB) -o $(NAME)

$(LIBFT_LIB):$(LIBFT_HEADER)
	@make -C utils/libft/


$(GET_NEXT_LINE)%.o:$(GET_NEXT_LINE)%.c $(GNL_HEADER)
	@$(CC) $(FlAGS) -c $< -o $@

%.o:%.c $(HEADER)
	@printf "\e[1;42m \e[0;m\e[1;42m \e[0;m\e[1;42m \e[0;m\e[1;42m \e[0;m\e[1;42m \e[0;m"
	@$(CC) $(FLAGS) -c $< -o $@

$(MLX_LIB):
	@make -C mlx 2> /dev/null

clean:
	@rm -rf $(SRC_OBJ)
	@rm -rf $(GNL_OBJ)
	@make fclean -C utils/libft
	@make clean -C mlx
	@echo $(R)[.o files deleted]$(RS)

fclean:clean
	@rm -rf $(NAME)
	@echo $(R)[cub3D deleted]$(RS) 

re:fclean $(NAME)


.PHONY:get_next_line all fclean clean
