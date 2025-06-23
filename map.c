#include "so_long.h"

static void	put_background(map_t map, t_data data)
{
	int		i;
	int		j;

	i = 0;
	while(map[i][j])
	{
		j = 0;
		while(map[i][j])
		{
			mlx_put_image_to_window(data->mlx, data->window, data->back, i, j);
			j++;
		}
		i++;
	}
}

static void	put_objects(map_t map, t_data data)
{
	int		i;
	int		j;

	i = 0;
	while(map[i][j])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->wall, i, j);
			else if(map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->obj, i, j);
			else if(map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->exit, i, j);
			else if(map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, data->player, i, j);
		}
		i++;
	}
}

static void	ber_to_char(map_t *map, const char *file_path)
{
	int		fd;
	int		i = 0;
	int		lines;
	char	*line;

	lines = map_h(map);
	map->map = malloc(sizeof(char *) * (lines + 1));
	if (!map->map)
	{
		handle_error();
		return ;
	}
	map[lines] = '\0';
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		handle_error();
		return ;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		map->map[i] = line;
		//if (i == 0)
			//map->width = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
		i++;
	}
	//map->height = i;
	close(fd);
}

void    create_map(map_t map, t_data data)
{
	ber_to_char(map, data);
	put_background(map, data);
	put_objects(map, data);
}