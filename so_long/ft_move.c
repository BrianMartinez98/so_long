#include "so_long.h"

static int is_valid_move(t_data *data, int new_x, int new_y)
{
    int map_x = new_x / TILE_SIZE;
    int map_y = new_y / TILE_SIZE;

    data->player_moves++;
    if (new_x < 0 || new_y < 0 || new_x >= data->size_x || new_y >= data->size_y)
        return (0);
    if (data->map->map[map_y][map_x] == '1')
        return 0;
    else if (data->map->map[map_y][map_x] == 'E')
    {
        data->flag = true;
        if (data->total_collectables == 0)
        {
            open_exit(data);
            return 1;
        }
    }
    else
        data->flag = false;
    if (data->map->map[map_y][map_x] == 'C')
        data->total_collectables--;
    printf("moves: %d\n", data->player_moves);
    return 1;
}


int key_hook(int keycode, t_data *data)
{
    int new_x = data->player_x;
    int new_y = data->player_y;

    if (keycode == 65307)
    {
        mlx_destroy_window(data->mlx, data->window); //poner ft_exit
        exit(0);
    }
    if (data->flag)
        data->map->map[data->player_y / TILE_SIZE][data->player_x / TILE_SIZE] = 'E';
    else
        data->map->map[data->player_y / TILE_SIZE][data->player_x / TILE_SIZE] = '0';
    if (keycode == 65361 || keycode == 97)
		new_x -= TILE_SIZE;
    else if (keycode == 65363 || keycode == 100)
        new_x += TILE_SIZE;
    else if (keycode == 65362 || keycode == 119)
        new_y -= TILE_SIZE;
    else if (keycode == 65364 || keycode == 115)
        new_y += TILE_SIZE;
    else
        return 0;
    if (is_valid_move(data, new_x, new_y))
    {
        data->player_x = new_x;
        data->player_y = new_y;
        if (data->map->map[new_y / TILE_SIZE][new_x / TILE_SIZE] != 'E')
            data->map->map[new_y / TILE_SIZE][new_x / TILE_SIZE] = 'P';
        create_map(data);
    }
    return 0;
}
