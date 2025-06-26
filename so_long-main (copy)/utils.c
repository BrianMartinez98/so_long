#include "so_long.h"

int count_lines(int fd)
{
	int		lines = 0;
	char	*line;

	lines = 0;
	while ((line = get_next_line(fd)))
	{
		lines++;
		free(line);
	}
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
		ft_printf("Error\nmap has to be .ber\n");
		exit(EXIT_FAILURE); 
	} 
	data->size_x = (line_lenght(fd) * TILE_SIZE); 
	data->size_y = (count_lines(fd) * TILE_SIZE + 32);
	close(fd);
}
