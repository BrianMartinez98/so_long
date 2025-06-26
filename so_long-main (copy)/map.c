#include "so_long.h"

void put_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
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

static void put_image(t_data *data, int i, int j)
{
    if (data->map[i][j] == '1')
        mlx_put_image_to_window(data->mlx, data->window, data->wall, 
                                j * TILE_SIZE, i * TILE_SIZE);
    else if (data->map[i][j] == 'C')
        mlx_put_image_to_window(data->mlx, data->window, data->obj, 
                                j * TILE_SIZE, i * TILE_SIZE);
    else if (data->map[i][j] == 'E')
    {    
        if (data->flag)
            mlx_put_image_to_window(data->mlx, data->window, data->player, 
                                j * TILE_SIZE, i * TILE_SIZE);
        else
            mlx_put_image_to_window(data->mlx, data->window, data->exit, 
                                j * TILE_SIZE, i * TILE_SIZE);
    }
    else if (data->map[i][j] == 'P')
    {
        mlx_put_image_to_window(data->mlx, data->window, data->player, 
                                j * TILE_SIZE, i * TILE_SIZE);
        data->player_x = j * TILE_SIZE;
        data->player_y = i * TILE_SIZE;
    }
}

static void objects(t_data *data)
{
    int i;
    int j;
    
    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            put_image(data, i, j);
            j++;
        }
        i++;
    }
}

void    open_exit(t_data *data)
{
    if (data->player_collectables == data->total_collectables)
    {   
        ft_printf("win");
        mlx_destroy_window(data->mlx, data->window);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }
}

void    create_map(t_data *data)
{
	put_background(data);
	objects(data);
}