#include "so_long.h"

void	handle_error(t_errorlst error, t_data *data)
{
    if (error == MALLOCERROR)
        ft_printf("Error Malloc!\n");
    else if (error == PARAMETROS)
        ft_printf("Error en los parametros!\n");
    else if (error == FD)
        ft_printf("Fallo en el fd!\n");
    else if (error == IMG_ERROR)
        ft_printf("Error en las imagenes!\n");
    else if (error == NOTRECTANGULAR)
        ft_printf("El mapa no tiene la forma correcta!\n");
    else if (error == NOTWALLS)
        ft_printf("El mapa no esta rodeado de muros!\n");
    else if (error == NOTPOSSIBLE)
        ft_printf("No es un mapa posible!\n");
    else if (error == IMG_ERROR)
        ft_printf("Error en las imagenes\n");
    else if (error == FD)
        ft_printf("Fallo en el fd\n");
	else if (error == FD)
        ft_printf("It is not a .ber\n");
	destroy_all(data);
}

void free_data(t_data *data)
{
    if (data)
	{
        if (data->map)
		{
            if (data->map)
			{
                for (int i = 0; data->map[i]; i++)
                    free(data->map[i]);
                free(data->map);
            }
            free(data->map);
        }
        if (data->file_name)
            free(data->file_name);
    }
}

void free_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}


int close_window(t_data *data)
{
    destroy_all(data);
    exit(0);
    return (0);
}

void    destroy_all(t_data *data)
{
	if (data->mlx)
	{
		if (data->exit)
			mlx_destroy_image(data->mlx, data->exit);
		else if (data->back)
			mlx_destroy_image(data->mlx, data->back);
		else if (data->player)
			mlx_destroy_image(data->mlx, data->player);
		else if (data->wall)
			mlx_destroy_image(data->mlx, data->wall);
		else if (data->obj)
			mlx_destroy_image(data->mlx, data->obj);
		mlx_destroy_window(data->mlx, data->window);
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

