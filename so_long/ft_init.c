#include "so_long.h"

int	ft_init(t_data *data, char **argv, int fd)
{
	int	lines;

	lines = count_lines(fd);
	data->mlx = NULL;
	data->window = NULL;
	data->player_x = 0;
	data->player_y = 0;
	data->size_y = 0;
	data->size_x = 0;
	data->player_moves = 0;
	data->fd = 0;
	data->flag = false;
	data->map->map = malloc(sizeof(char *) * (lines + 1));
	if (!data->map->map)
	{
		write(2, "Error4\n", 7);
		handle_error();
	}
	data->map->map[lines] = NULL;
	data->collectables = 0;
	data->file_name = malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));
	if (!data->file_name)
		return (1);
	ft_strcpy(data->file_name, argv[1]);
	return (0);
}

void ft_img_init(t_data *data)
{
    int width;
    int height;
    
    data->back = mlx_xpm_file_to_image(data->mlx, "rs/back.xpm", &width, &height);
    data->obj = mlx_xpm_file_to_image(data->mlx, "rs/obj.xpm", &width, &height);
    data->wall = mlx_xpm_file_to_image(data->mlx, "rs/wall.xpm", &width, &height);
    data->player = mlx_xpm_file_to_image(data->mlx, "rs/player.xpm", &width, &height);
    data->exit = mlx_xpm_file_to_image(data->mlx, "rs/exit.xpm", &width, &height);
    if (!data->back || !data->obj || !data->wall || !data->player || !data->exit)
    {
        write(2, "Error: Failed to load images\n", 27);
        handle_error();
    }
}

void    find_player(t_data *data)
{
    char	*place;

    place = find_place(data, 'P');
	if (!place)
	{
		return ;
	}
    data->player_x = place[0];
    data->player_y = place[1];
}
