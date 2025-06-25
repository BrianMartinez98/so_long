#include "so_long.h"

static int rectangular(t_data *data) 
{
    int i = 0;
    int j;

	i = 0;
    if (!data->map->map[0] || data->map->width == 0)
        return (0);
    while (data->map->map[i])
    {
        j = 0;
        while (data->map->map[i][j] && data->map->map[i][j] != '\n')
            j++;
        if (j != data->map->width)
            return (0);
        i++;
    }
    return (1);
}

static int walls(t_data *data)
{
    int i;
    int j;
    
    if (!data->map->map || !data->map->map[0])
        return 0;

    i = 0;
    while (i < data->map->height)
    {
        j = 0;
        while (j < data->map->width)
        {
            if ((j == 0 || j == data->map->width - 1) && data->map->map[i][j] != '1')
                return 0;
            if ((i == 0 || i == data->map->height - 1) && data->map->map[i][j] != '1')
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

char	**duplicate_map(char **original, int height)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

char *find_place(t_data *data, char a)
{    
    int i;
    int j;
    char *exitp;

	i = 0;
    exitp = (char *)malloc(sizeof(char) * 3);
    if (!exitp)
        return NULL;
    while (data->map->map[i])
    {
        j = 0;
        while (data->map->map[i][j])
        {
            if (data->map->map[i][j] == a)
            {
                exitp[0] = i;
                exitp[1] = j;
                return (exitp);
            }
            j++;
        }
        i++;
    }
    free(exitp);
    return (NULL);
}

static void ft_painting(t_data *data, int row, int colum, char **map)
{
	if (row < 0 || colum < 0 || row >= data->map->height)
		return;
	if (colum >= (int)ft_strlen(map[row]))
		return;

	char current = map[row][colum];

	if (current == 'r' || current == '1')
		return;
	if (current == '0' || current == 'C')
	{
		if (current == 'C')
			data->collectables++;
		map[row][colum] = 'r';
	}
	else if (current == 'E')
	{
		data->map->exit = 1;
		return;
	}
	ft_painting(data, row + 1, colum, map);
	ft_painting(data, row - 1, colum, map);
	ft_painting(data, row, colum + 1, map);
	ft_painting(data, row, colum - 1, map);
}



static int	possible(t_data *data)
{	
	char	*place;
	char	**map_copy;
	map_copy = duplicate_map(data->map->map, data->map->height);
	if (!map_copy)
		return 0;
	data->collectables = 0;
	data->map->exit = 0;
	place = find_place(data, 'P');
	if (!place)
	{
		free_map(map_copy);
		return 0;
	}
	ft_painting(data, place[0], place[1], map_copy);
	free(place);
	free_map(map_copy);
	if (data->map->exit == 0 || data->collectables != data->total_collectables)
		return 0;
	return 1;
}


static void ber_to_char(t_data *data, int fd)
{
    int i = 0;
    char *line;

    while ((line = get_next_line(fd)))
    {
        data->map->map[i] = line;
        if (i == 0)
            data->map->width = ft_strlen(line) - 1;
        i++;
    }
    data->map->height = i;
    close(fd);
}

static void count_collectables(t_data *data)
{
    int i;
    int j;
    
    i = 0;
    while (data->map->map[i])
    {
        j = 0;
        while (data->map->map[i][j])
        {
            if (data->map->map[i][j] == 'C')
                data->total_collectables += 1;       
            j++;
        }
        i++;
    }
}

void	map_checker(t_data *data)
{
	ber_to_char(data, data->fd);
    count_collectables(data);
	if (!rectangular(data))
	{
		write(2, "Error1\n", 7);
		handle_error();
	}
	if (!walls(data))
	{
		write(2, "Error2\n", 7);
		handle_error();
	}
	if (!possible(data))
	{
		write(2, "Error3\n", 7);
		handle_error();
	}
}
