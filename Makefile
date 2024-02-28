CC = cc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address -g
MLX_FLAGS = -framework OpenGL -framework Appkit
INCS = -Iinclude

LIBFT = ./lib/libft.a
MLX = ./mlx/libmlx.a

NAME = miniRT

SRC_DIR = src
MLX_DIR = mlx
LIB_DIR = lib

LIBS = $(addprefix $(LIB_DIR)/, $(LIB_NAME))

HIT_SRC = hit_obj.c hit.c
PARSE_SRC = parse.c set_object.c set_scene.c
UTIL_SRC = get_next_line.c list_utils.c parse_utils.c utils.c vec_utils.c print.c
MAIN_SRC = check_arg.c main.c scene.c ray.c phong_light.c

SRCS = $(addprefix $(SRC_DIR)/hit/, $(HIT_SRC)) \
		$(addprefix $(SRC_DIR)/parse/, $(PARSE_SRC)) \
		$(addprefix $(SRC_DIR)/util/, $(UTIL_SRC)) \
		$(addprefix $(SRC_DIR)/, $(MAIN_SRC))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCS) $(LIBFT) $(MLX_FLAGS) $(MLX) -o $@ $^

$(LIBFT):
	make -C $(LIB_DIR)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	make -C $(LIB_DIR) fclean
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
