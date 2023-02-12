CC = cc
CFLAGS = -Wall -Werror -Wextra
LFLAGS =  -L ./minilibx -lmlx -framework OpenGL -framework Appkit

SRCS = main.c init.c init_player.c put_background.c validity_check.c \
	map.c parse.c size.c str.c type.c game.c put_texture.c render_dda.c \
	hook.c

NAME = cub3d
RM = rm -rf

SRCS_DIR = src/cub3d/
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))

# LIBFT
LIBFT_DIR = src/libft/
LIBFT_A = $(addprefix $(LIBFT_DIR), libft.a)

# MLX
MLX_DIR = minilibx/
MLX_PATH = $(addprefix, $(MLX_DIR), libmlx.a)

INCS = includes/
OBJS = $(SRCS_PATH:.c=.o)

ifdef sanitize
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
endif

%.o : %.c
	@echo "$(YELLOW) *** Generating object files ... *** $(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS) -I$(LIBFT_DIR)

all : $(NAME)
	@echo "$(GREEN) *** Project Ready! *** $(DEFAULT)"

$(NAME) : $(OBJS)
	@echo "$(GREEN) *** Compiling cub3d ... *** $(DEFAULT)"
	@make -C src/libft
	@make -C minilibx
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A)
	@echo "$(GREEN) *** Compile Done!! *** $(DEFAULT)"

clean :
	@echo "$(RED) *** Deleting objects ... *** $(DEFAULT)"
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	@echo "$(RED) *** Deleting executable ... *** $(DEFAULT)"
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) clean
	@$(RM) $(NAME)

re :
	@make fclean
	@make all

bonus : 
	@echo "$(GREEN) *** Bonus Compiling ... *** $(DEFAULT)"
	@make all

sanitize :
	@make sanitize=1 re

.PHONY: all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
