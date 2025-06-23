#include "so_long"

char	*find_entrance(map_t map, char a)
{	
	int		i;
	int		j;
	char	*exitp;

	exitp = (char *)malloc(sizeof(char) * 2);
	i = 1;
	while(map[i][j])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == a);
			{
				exitp[0] = i;
				exitp[1] = j;
				exitp[2] = '\0';
			}
			j++;
		}
		i++;
	}
	return (exitp);
}

void	paiting(map_t map, int row, int colum)
{
	if (map[row][colum] == 0)
		map[row][colum] = r;
	if (map[row + 1][colum] == 0)
	{
		map[row + 1][colum] = r;
		painting(map, row + 1, colum);
	}
	if (map[row - 1][colum] == 0)
	{
		map[row - 1][colum] = r;
		painting(map, row - 1, colum);
	}
	if (map[row][colum + 1] == 0)
	{
		map[row][colum + 1] = r;
		painting(map, row, colum + 1);
	}
	if (map[row][colum - 1] == 0)
	{
		map[row][colum - 1] = r;
		painting(map, row, colum - 1);
	}
}