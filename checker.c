#include "so_long.h"

static int	rectangular(map_t map)
{
	int		i;
	int		j;
	int		len;
	int		h;

	i = 0;
	len = line_len(map);
	h = map_h(map);
	while(map[i][j])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] != '1' || map[i][j] != '0' || map[i][j] != 'E' 
								|| map[i][j] != 'P' || map[i][j] != 'C')
				return (0);
			j++;
		}
		if (j != len)
			return (0);
		i++;
	}
	if (i != h)
		return (0);
	return (1);
}

static int	walls(map_t map)
{
	int		i;
	int		j;
	int		len;
	int		h;

	i = 0;
	len = line_len(map);
	h = map_h(map);
	while(map[i][j])
	{
		j = 0;
		while(map[i][j])
		{
			if ((j == 0 && map[i][j] != 1) || (j == h && map[i][j] != 1))
				return (0);
			if ((i == 0 && map[i][j] != 1) || (i == len && map[i][j] != 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	possible(map_t map)
{	
	char	*place;
	int		x;
	int		y;

	place = find_entrance(map, P);
	ft_painting(map, place);
	place = find_entrance(map, E);
    x = place[0];
    y = place[1];
    free(place);

    if (map[x + 1][y] == 'r' || map[x - 1][y] == 'r' ||
        map[x][y + 1] == 'r' || map[x][y - 1] == 'r')
        return 0;
    return 1;
}

void	map_checker(map_t map)
{
	if (!rectangular(map))
		handle_error();
	if (!walls(map))
		handle_error();
	if (!possible(map))
		handle_error();
}
