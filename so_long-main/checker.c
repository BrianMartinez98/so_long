#include "so_long.h"

static int	rectangular(map_t *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(map->map[i][j])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (map->map[i][j] != '1' || map->map[i][j] != '0' || map->map[i][j] != 'E' 
								|| map->map[i][j] != 'P' || map->map[i][j] != 'C')
				return (0);
			j++;
		}
		if (j != map->width)
			return (0);
		i++;
	}
	if (i != map->height)
		return (0);
	return (1);
}

static int	walls(map_t *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(map->map[i][j])
	{
		j = 0;
		while(map->map[i][j])
		{
			if ((j == 0 && map->map[i][j] != 1) || (j == map->height && map->map[i][j] != 1))
				return (0);
			if ((i == 0 && map->map[i][j] != 1) || (i == map->width && map->map[i][j] != 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	possible(map_t *map)
{	
	char	*place;
	int		x;
	int		y;

	place = find_entrance(map,'P');
	ft_painting(map, place[0], place[1]);
	place = find_entrance(map, 'E');
    x = place[0];
    y = place[1];
    free(place);

    if (map->map[x + 1][y] == 'r' || map->map[x - 1][y] == 'r' ||
        map->map[x][y + 1] == 'r' || map->map[x][y - 1] == 'r')
        return 0;
    return 1;
}

void	map_checker(map_t *map)
{
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
