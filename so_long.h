#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 32

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "get_next_line.h"

typedef struct map_s
{
	char	**map;
	int		width;
	int		height;
	int		exit;
}				map_t;

typedef struct s_data
{
	map_t		*map;
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
	int			fd;
	int			player_x;
	int			player_y;
	int			total_collectables;
	int			collectables;
	int			player_collectables;
	int			player_moves;
	bool		flag;
}				t_data;

void	map_checker(t_data *data);
void	create_map(t_data *data);
void	handle_error(void);
int		ft_init(t_data *data, char **argv, int fd);
int		count_lines(int fd);
char	*ft_strcpy(char *s1, char *s2);
int		line_lenght(int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_img_init(t_data *data);
void	window_size(t_data *data, char **argv);
int		key_hook(int keycode, t_data *data);
void	*ft_memset(void *b, int c, size_t len);
char 	*ft_strdup(char *src);
void 	free_map(char **map);
void    open_exit(t_data *data);
char 	*find_place(t_data *data, char a);
//void 	free_data(t_data *data);

#endif