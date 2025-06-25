NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = minilibx-linux/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz

GNL_PATH = get_next_line/

CFILES = \
	error_free.c\
	map.c\
	checker.c\
	main.c\
	checker_utils.c\
	ft_init.c\
	ft_move.c\
	$(GNL_PATH)get_next_line.c\
	$(GNL_PATH)get_next_line_utils.c\

OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(GNL_PATH) -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) -o $(NAME)

clean:
	@make -C $(MLX_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette *.c *.h $(GNL_PATH)*.c $(GNL_PATH)*.h

.PHONY: all clean fclean re norm
