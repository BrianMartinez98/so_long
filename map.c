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

static void	ber_to_char(map_t map, t_data data)
{
	int		i;
	int		j;
	int 	fd;

	fd = open("maps/a.ber", O_RDONLY);
	i = 0;
	while(map->map[i][j])
	{
		j = 0;
		while(map->map[i][j])
		{
			
		}
		i++;
	}
}

void    create_map(map_t map, t_data data)
{
	ber_to_char(map, data);
	put_background(map, data);
	put_objects(map, data);
}