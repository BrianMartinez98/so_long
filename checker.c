#include "so_long.h"

static int	possible(map_t map)
{	
	char	*place;
	int		x;
	int		y;

	place = find_entrance(map, P);
	painting(map, place);
	place = find_entrance(map, E);
    x = place[0];
    y = place[1];
    free(place);

    if (map[x + 1][y] == 'r' || map[x - 1][y] == 'r' ||
        map[x][y + 1] == 'r' || map[x][y - 1] == 'r')
        return 0;

    return 1;
}

static int	walls(map_t map)
{
	int		i;
	int		j;

	i = 0;
	while(map[i][j])
	{
		j = 0;
		while(map[i][j])
		{
			if (i == 0 && map[i][j] != 1);
				return (0);
			if (i == 0 && map[i][j] != 1);
				return (0);
			j++;
		}
		i++;
	}
}

void	map_checker(map_t map)
{
	if (!walls(map))
		handle_error();
	if (!possible(map))
		handle_error();
}
