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

static void put_objects(map_t *map, t_data *data)
{
    int i = 0;
    int j;
    
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->window, data->wall, 
                                       j * TILE_SIZE, i * TILE_SIZE);
            else if (map->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->window, data->obj, 
                                       j * TILE_SIZE, i * TILE_SIZE);
            else if (map->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->window, data->exit, 
                                       j * TILE_SIZE, i * TILE_SIZE);
            else if (map->map[i][j] == 'P')
                mlx_put_image_to_window(data->mlx, data->window, data->player, 
                                       j * TILE_SIZE, i * TILE_SIZE);
            j++;
        }
        i++;
    }
}

void    create_map(map_t *map, t_data *data)
{
	put_background(map, data);
	put_objects(map, data);
}