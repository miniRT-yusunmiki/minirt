CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

NAME = miniRT
SRC_DIR = src

MAIN_SRC = main.c

SRCS = $(addprefix $(SRC_DIR)/, $(MAIN_SRC))
OBJS = $(SRCS:.c=.o)

all :  $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX) -o $@ $^

%.o : $(SRC_DIR)/$(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
