#include "so_long.h"

static void	check_filename(const char *filename, t_data *data)
{
	int len = ft_strlen(filename);

	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
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
    
    check_filename(argv[1], data);
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
