#include "so_long.h"

char	*find_entrance(map_t *map, char a)
{	
	int		i;
	int		j;
	char	*exitp;

	exitp = (char *)malloc(sizeof(char) * 2);
	i = 1;
	j = 0;
	while(map->map[i][j])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (map->map[i][j] == a)
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

void	ft_painting(map_t *map, int row, int colum)
{
	if (map->map[row][colum] == 0)
		map->map[row][colum] = 'r';
	else if (map->map[row][colum] == 'C')
	{
		map->collectables ++;
		map->map[row][colum] = 'r';
	}
	else if (map->map[row][colum] == 'E')
	{
		map->exit = 1;
		return ;
	}
	else
		return ;
	ft_painting(map, row + 1, colum);
	ft_painting(map, row - 1, colum);
	ft_painting(map, row, colum + 1);
	ft_painting(map, row, colum - 1);
}

void	img_init(t_data *data)
{
	int width;
    int height;
	
	data->back = mlx_xpm_file_to_image(data->mlx, "rs/floor.xpm", &width, &height);
	data->obj = mlx_xpm_file_to_image(data->mlx, "rs/obj.xpm", &width, &height);
	data->wall = mlx_xpm_file_to_image(data->mlx, "rs/wall.xpm", &width, &height);
	data->player = mlx_xpm_file_to_image(data->mlx, "rs/player.xpm", &width, &height);
	data->exit = mlx_xpm_file_to_image(data->mlx, "rs/exit.xpm", &width, &height);
}

int count_lines(int fd)
{
	int		lines = 0;
	char	*line;

	while ((line = get_next_line(fd)))
	{
		lines++;
		free(line);
	}
	close(fd);
	return (lines);
}

int	line_lenght(int fd)
{
	int		length;
	int		bytes;
	char	buffer[1];

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}
void	window_size(t_data *data, char **argv)
{ 
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)  
	{
		perror("Error\nInvalid map_path/map\n");
		exit(EXIT_FAILURE); 
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		printf("Error\nmap has to be .ber\n");
		exit(EXIT_FAILURE); 
	} 
	data->size_x = (line_lenght(fd) * TILE_SIZE); 
	data->size_y = (count_lines(fd) * TILE_SIZE);
}

char    *ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
