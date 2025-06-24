#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 8

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_data
{
	void		*mlx;
	void		*window;
	char		*back;
	char		*obj;
	char		*wall;
	char		*player;
	char		*exit;
	char		*file_name;
	int			size_x;
	int			size_y;
}				t_data;

typedef struct map_s
{
	char	**map;
	int		width;
	int		height;
	int		collectables;
	int		exit;
}				map_t;

char	*find_entrance(map_t *map, char a);
void	ft_painting(map_t *map, int row, int colum);
void	map_checker(map_t *map);
void	create_map(map_t *map, t_data *data, int fd);
void	handle_error(void);
int		ft_init(t_data *data, map_t *map, char **argv, int fd);
int		count_lines(int fd);
char	*ft_strcpy(char *s1, char *s2);
int		line_lenght(int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif