#include "so_long.h"

int main (int argc, char **argv)
{
	t_data	*data;
	map_t	*map;
	int		fd;

// check parametres
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
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error5\n", 7);
		handle_error();
	}
	ft_init(data, map, argv, fd);
	ft_strcpy(data->file_name, argv[1]);
	printf("Archivo: [%s]\n", data->file_name);
// Open window
	data->mlx = mlx_init();
	if (NULL == data->mlx)
		return (1);
	printf("data->mlx = %p\n", data->mlx);
	data->window = mlx_new_window(data->mlx, 100, 100, "My window");
	if (NULL == data->window)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (1);
    }
	printf("data->win = %p\n", data->window);
// create map
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error5\n", 7);
		handle_error();
	}
	create_map(map, data, fd);
// Check map
    map_checker(map);
    // event loop
	mlx_loop(data->mlx); // keeps the process alive
// finish program
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}