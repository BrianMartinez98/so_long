#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*back;
	void	*obj;
	void	*wall;
	void	*player;
	void	*exit;	
}				t_data

typedef struct map_s
{
	char	**map;
}				map_t

char	*find_entrance(map_t map, char a);
void	ft_paiting(map_t map, int row, int colum);
void	map_checker(map_t map);
void	create_map(map_t map, t_data data);
int		map_h(map_t map);
int		line_len(map_t map);
void	handle_error(void);

#endif