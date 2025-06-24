#include "so_long.h"

int main (int argc, char **argv)
{
	t_data	*data;
	map_t	*map;

	if (argc != 2)
	{
		write(1, "ErrorP\n", 7);
		handle_error();
	}
	data = malloc(sizeof(t_data));
	map  = malloc(sizeof(map_t));
	if (!data || !map)
	{
		return (1);
	}
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
	{
		write(2, "Error5\n", 7);
		handle_error();
	}
	ft_init(data, map, argv, data->fd);
	window_size(data, argv);
	data->mlx = mlx_init();
	if (NULL == data->mlx)
		return (1);
	data->window = mlx_new_window(data->mlx, data->size_x, data->size_y, "My window");
	if (NULL == data->window)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (1);
    }
	ft_img_init(data);
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
	{
		write(2, "Error5\n", 7);
		handle_error();
	}
	map_checker(map, data);
	create_map(map, data);
	mlx_loop(data->mlx);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
