#include "so_long.h"

static void	check_filename(t_data *data)
{
	data->file_name = data->file_name + (ft_strlen(data->file_name) - 4);
	if (ft_strncmp(data->file_name, ".ber", 4))
		handle_error(BER, data);
}

//mover directorio
void	check_chars(t_data *data)
{
	int i;
	int j;

	i = (data->size_y) - 1;
	data->enumb = 0;
	data->pnumb = 0;
	while (i >= 0)
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (!ft_strchr(CHARS, data->map[i][j]))
				handle_error(INVALID_CHARS, data);
			if (data->map[i][j] == 'E')
				data->enumb++;
			if (data->map[i][j] == 'P')
				data->pnumb++;
			j++;
		}
		i--;
	}
	if (data->pnumb > 1 || data->enumb > 1)
		handle_error(INVALID_PE, data);
}

//mejorar la logica del fd
int ft_init(t_data *data, char **argv)
{
    int lines;
    
	if (data->file_name)
    	free(data->file_name);
	data->file_name = NULL;
    data->file_name = malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));
    if (!data->file_name)
        handle_error(MALLOCERROR, data);
    ft_strcpy(data->file_name, argv[1]);
    check_filename(data);
    data->fd = open(argv[1], O_RDONLY);
    if (data->fd < 0)
        handle_error(FD, data);
    lines = count_lines(data->fd);
    close(data->fd);
    data->map = malloc(sizeof(char *) * (lines + 1));
    if (!data->map)
        handle_error(MALLOCERROR, data);
    data->map[lines] = NULL;
    data->fd = open(argv[1], O_RDONLY);
    if (data->fd < 0) 
        handle_error(FD, data);
	
    window_size(data, argv);
    map_checker(data);
    return (0);
}

//cambiar directorio
void    find_player(t_data *data)
{
    char	*place;

    place = find_place(data, 'P');
	if (!place)
		return ;
    data->player_x = (int)place[0];
    data->player_y = (int)place[1];
}
