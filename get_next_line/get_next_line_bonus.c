/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:02:28 by brimarti          #+#    #+#             */
/*   Updated: 2024/11/06 15:03:15 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*chop(char *buffer)
{
	int		i;
	char	*next_line;

	i = 0;
	if (!buffer[i])
	{
		return (NULL);
	}
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	next_line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		next_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		next_line[i++] = '\n';
	return (next_line);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

static char	*update_append(char *append, char *temp, int bytes_read)
{
	char	*temp_append;

	temp[bytes_read] = '\0';
	temp_append = ft_strjoin(append, temp);
	free (append);
	return (temp_append);
}

static char	*reader(int fd, char *append)
{
	int		bytes_read;
	char	*temp;

	if (!append)
		append = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		append = update_append(append, temp, bytes_read);
		if (!append || ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	if (bytes_read < 0)
	{
		free(append);
		return (NULL);
	}
	return (append);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = reader(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = chop(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}
