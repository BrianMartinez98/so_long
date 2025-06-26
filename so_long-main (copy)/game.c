#include "so_long.h"

void	game_init(t_data *data)
{
	data->mlx = mlx_init();
	if (NULL == data->mlx)
		return ;
	data->window = mlx_new_window(data->mlx, data->size_x, data->size_y, "Fxck");
	if (NULL == data->window)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return ;
    }
	ft_img_init(data);
	create_map(data);
	mlx_hook(data->window, KEY_PRESS, 1L >> 0, key_hook, data);
	mlx_hook(data->window, MOUSE_PRESS, 0, close_window, data);
	mlx_loop(data->mlx);
}
