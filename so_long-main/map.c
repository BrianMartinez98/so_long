#include "so_long.h"

void put_background(map_t *map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			mlx_put_image_to_window(
				data->mlx,
				data->window,
				data->back,
				j * TILE_SIZE,
				i * TILE_SIZE
			);
			j++;
		}
		i++;
	}
}

static void	put_objects(map_t *map, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(map->map[i][j])
	{
		j = 0;
		while(map->map[i][j])
		{
			if(map->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->wall, i, j);
			else if(map->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->obj, i, j);
			else if(map->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->exit, i, j);
			else if(map->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, data->player, i, j);
		}
		i++;
	}
}

static void	ber_to_char(map_t *map, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map->map[i] = line;
		if (i == 0)
			map->width = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
		i++;
	}
	map->height = i;
	close(fd);
}

void    create_map(map_t *map, t_data *data, int fd)
{
	ber_to_char(map, fd);
	put_background(map, data);
	put_objects(map, data);
}