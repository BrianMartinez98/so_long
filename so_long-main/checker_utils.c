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
		printf("Error\nmap has to be .ber\n");
		exit(EXIT_FAILURE); 
	} 
	data->size_x = (line_lenght(fd) * TILE_SIZE); 
	data->size_y = (count_lines(fd) * TILE_SIZE);
	close(fd);
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
