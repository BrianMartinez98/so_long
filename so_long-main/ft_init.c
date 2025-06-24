#include "so_long.h"

int	ft_init(t_data *data, map_t *map, char **argv, int fd)
{
	int	lines;

	lines = count_lines(fd);
	data->mlx = NULL;
	data->window = NULL;
	data->back = "rs/back.xpm";
	data->obj = "rs/obj.xpm";
	data->wall = "rs/wall.xpm";
	data->player = "rs/player.xpm";
	data->exit = "rs/exit.xpm";
	printf("data->back = %p\n", data->back);
	map->map = malloc(sizeof(char *) * (lines + 1));
	if (!map->map)
	{
		write(2, "Error4\n", 7);
		handle_error();
	}
	map->map[lines] = NULL;
	map->collectables = 0;
    map->exit = 0;
	data->file_name = malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));
	if (!data->file_name)
		return (1);
	return (0);
}
