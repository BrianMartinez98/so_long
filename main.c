#include "so_long.h"

void map_checker(map_t map)
{
    int i;
    int j;

    i = 0;
    while(matrix[][])
    {
        j = 0;
        while(matrix[][])
        {
            // mapa rectangular
            // mapa con muros
            // recorrido posible
        }
    }
}

int main (int argc, char **argv)
{
    void	*mlx_connection;
	void	*mlx_window;

// check parametres
	if (argc != x)
	{
		handle_error();
	}
// Check map
    map_checker(map_t map);
// Open window
	mlx_connection = mlx_init();
	if (NULL == mlx_connection)
		return (MALLOC_ERROR);
	mlx_window = mlx_new_window(mlx_connection, HEIGHT, WIDTH, "My window");
	if (NULL == mlx_window)
	{
		mlx_destroy_display(mlx_connection); // Cleanup MLX connection
		free(mlx_connection);
		return (MALLOC_ERROR);
    }
    // event loop
	mlx_loop(mlx_connection); // keeps the process alive
// create map
	create_map(map, data);
// put player

// finish program


	mlx_destroy_window(mlx_connection, mlx_window);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
}