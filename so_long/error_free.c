#include "so_long.h"

void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/*
void free_data(t_data *data)
{
    if (data)
	{
        if (data->map)
		{
            if (data->map->map)
			{
                for (int i = 0; data->map->map[i]; i++)
                    free(data->map->map[i]);
                free(data->map->map);
            }
            free(data->map);
        }
        if (data->file_name)
            free(data->file_name);
        if (data->mlx)
		{
            if (data->back) mlx_destroy_image(data->mlx, data->back);
            if (data->wall) mlx_destroy_image(data->mlx, data->wall);
            if (data->player) mlx_destroy_image(data->mlx, data->player);
            if (data->exit) mlx_destroy_image(data->mlx, data->exit);
            if (data->obj) mlx_destroy_image(data->mlx, data->obj);
            if (data->window) mlx_destroy_window(data->mlx, data->window);
            mlx_destroy_display(data->mlx);
            free(data->mlx);
        }
        free(data);
    }
}
*/

void free_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
