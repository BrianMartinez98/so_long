#include "so_long.h"

//mejorar la logica del fd
int	ft_init(t_data *data, char **argv)
{
	int	lines;
	
	if (!data->file_name)
		handle_error(MALLOCERROR, data);
	ft_strcpy(data->file_name, argv[1]);
	if (!ft_strncmp(data->file_name, ".ber", 4))
	handle_error(BER, data);
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
		handle_error(FD, data);
	lines = count_lines(data->fd);
	data->map = malloc(sizeof(char *) * (lines + 1));
	if (!data->map)
		handle_error(MALLOCERROR, data);
	data->map[lines] = NULL;
	data->file_name = malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0) 
		handle_error(FD, data);
	window_size(data, argv);
	map_checker(data);
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
        handle_error(IMG_ERROR, data);
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
