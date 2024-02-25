CC = cc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address -g
MLX_FLAGS = -framework OpenGL -framework Appkit
INCS = -Iinclude

LIBFT = ./lib/libft.a
MLX = ./mlx/libmlx.a

NAME = miniRT

SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = mlx
LIB_DIR = lib

SRC_FILE = check_arg.c free.c get_next_line.c list_utils.c main.c parse_object.c parse_scene.c parse_utils.c parse.c scene.c vec_utils.c

LIBS = $(addprefix $(LIB_DIR)/, $(LIB_NAME))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILE))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILE:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCS) $(LIBFT) $(MLX_FLAGS) $(MLX) -o $@ $^

$(LIBFT):
	make -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(LIB_DIR) fclean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
