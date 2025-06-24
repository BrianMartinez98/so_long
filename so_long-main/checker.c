#include "so_long.h"

static int rectangular(map_t *map) 
{
    int i = 0;
    int j;

	i = 0;
    if (!map->map[0] || map->width == 0)
        return (0);
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j] && map->map[i][j] != '\n')
            j++;
        if (j != map->width)
            return (0);
        i++;
    }
    return (1);
}

static int walls(map_t *map)
{
    int i;
    int j;
    
    if (!map->map || !map->map[0])
        return 0;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if ((j == 0 || j == map->width - 1) && map->map[i][j] != '1')
                return 0;
            if ((i == 0 || i == map->height - 1) && map->map[i][j] != '1')
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

static char *find_entrance(map_t *map, char a)
{    
    int i;
    int j;
    char *exitp;

	i = 0;
    exitp = (char *)malloc(sizeof(char) * 3);
    if (!exitp)
        return NULL;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == a)
            {
                exitp[0] = i;
                exitp[1] = j;
                return exitp;
            }
            j++;
        }
        i++;
    }
    free(exitp);
    return NULL;
}

static void ft_painting(map_t *map, int row, int colum)
{
    if (row < 0 || colum < 0 || row >= map->height || colum >= map->width)
        return ;
    if (map->map[row][colum] == 'r' || map->map[row][colum] == '1')
        return ;
    if (map->map[row][colum] == '0' || map->map[row][colum] == 'C')
    {
        if (map->map[row][colum] == 'C')
            map->collectables++;
        map->map[row][colum] = 'r';
    }
    else if (map->map[row][colum] == 'E')
    {
        map->exit = 1;
        return ;
    }
    else
        return ;
    if (row + 1 < map->height)
        ft_painting(map, row + 1, colum);
    if (row - 1 >= 0)
        ft_painting(map, row - 1, colum);
    if (colum + 1 < map->width)
        ft_painting(map, row, colum + 1);
    if (colum - 1 >= 0)
        ft_painting(map, row, colum - 1);
}

static int	possible(map_t *map)
{	
	char	*place;
	int		x;
	int		y;

	place = find_entrance(map,'P');
	if (!place)
        return 0;
	ft_painting(map, place[0], place[1]);
	free(place);
	place = find_entrance(map, 'E');
	if (!place)
        return 0;
    x = place[0];
    y = place[1];
    free(place);

    if (map->map[x + 1][y] == 'r' || map->map[x - 1][y] == 'r' ||
        map->map[x][y + 1] == 'r' || map->map[x][y - 1] == 'r')
        return 0;
    return 1;
}

static void ber_to_char(map_t *map, int fd)
{
    int i = 0;
    char *line;

    while ((line = get_next_line(fd)))
    {
        map->map[i] = line;
        if (i == 0)
            map->width = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
        i++;
    }
    map->height = i;
    close(fd);
}

void	map_checker(map_t *map, t_data *data)
{
	ber_to_char(map, data->fd);
	if (!rectangular(map))
	{
		write(2, "Error1\n", 7);
		handle_error();
	}
	if (!walls(map))
	{
		write(2, "Error2\n", 7);
		handle_error();
	}
	if (!possible(map))
	{
		write(2, "Error3\n", 7);
		handle_error();
	}
}
