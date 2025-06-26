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
		handle_error(BER, data);
	data->size_x = (line_lenght(fd));
	data->size_y = (count_lines(fd));
	close(fd);
}
