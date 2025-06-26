NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = minilibx-linux/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz

GNL_PATH = get_next_line/

PRINTF_PATH = ft_printf/
FT_PRINTF_LIB = $(PRINTF_PATH)libftprintf.a

CFILES = \
	error_free.c\
	map.c\
	checker.c\
	main.c\
	checker_utils.c\
	ft_init.c\
	ft_move.c\
	game.c\
	libft.c\
	utils.c\
	$(GNL_PATH)get_next_line.c\
	$(GNL_PATH)get_next_line_utils.c\

OBJECTS = $(CFILES:.c=.o)

all: subsystems ft_printf $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(GNL_PATH) -I$(PRINTF_PATH) -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all

ft_printf:
	@make -C $(PRINTF_PATH) all

$(NAME): $(OBJECTS) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(FT_PRINTF_LIB) -o $(NAME)

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(PRINTF_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -f $(FT_PRINTF_LIB)

re: fclean all

.PHONY: all clean fclean re norm subsystems ft_printf
