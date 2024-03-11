CC = cc
CFLAGS = -Werror -Wall -Wextra
MLX_FLAGS = -framework OpenGL -framework Appkit
INCS = -Iinclude

LIBFT = ./lib/libft.a
MLX = ./mlx/libmlx.a

NAME = miniRT

SRC_DIR = src
MLX_DIR = mlx
LIB_DIR = lib

LIBS = $(addprefix $(LIB_DIR)/, $(LIB_NAME))

HIT_SRC = hit_cylinder_curv.c hit_cylinder.c hit_plane.c hit_sphere.c hit.c
LIGHT_SRC = diffuse.c shadow.c
PARSE_SRC = check_arg.c parse.c set_cam.c set_object.c set_scene.c
PIXEL_SRC = cam_dir_change.c cam_move.c key_hook.c pixel_put.c
RAY_SRC = ray.c shoot_ray.c
UTIL_SRC = ft_atof.c get_next_line.c list_utils.c parse_utils.c utils.c\
			vec_utils_basic.c vec_utils_create.c vec_utils_product.c
MAIN_SRC = main.c

SRCS = $(addprefix $(SRC_DIR)/hit/, $(HIT_SRC)) \
		$(addprefix $(SRC_DIR)/light/, $(LIGHT_SRC)) \
		$(addprefix $(SRC_DIR)/parse/, $(PARSE_SRC)) \
		$(addprefix $(SRC_DIR)/pixel/, $(PIXEL_SRC)) \
		$(addprefix $(SRC_DIR)/ray/, $(RAY_SRC)) \
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
