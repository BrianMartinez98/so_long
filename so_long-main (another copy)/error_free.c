#include "so_long.h"

static void print_errors(t_errorlst error, char *error_msg[])
{
    write(2, "ERROR: ", 7);
    if (error == FD)
        perror("open");
    else if (error >= 0 && error_msg[error])
        write(2, error_msg[error], ft_strlen(error_msg[error]));
    else
        write(2, "Unknown error\n", 14);
}

void	handle_error(t_errorlst error, t_data *data)
{
    char    *error_msg[42];

    error_msg[PARAMETROS] = "Error en los parametros!\n";
    error_msg[MALLOCERROR] = "Error Malloc!\n";
    error_msg[FD] = "Fallo en el fd!\n";
    error_msg[IMG_ERROR] = "Error en las imagenes!\n";
    error_msg[NOTRECTANGULAR] = "El mapa no tiene la forma correcta!\n";
    error_msg[NOTWALLS] = "El mapa no esta rodeado de muros!\n";
    error_msg[NOTPOSSIBLE] = "No es un mapa posible!\n";
    error_msg[BER] = "It is not a .ber!\n";
    error_msg[INVALID_CHARS] = "Not correct characters!\n";
    error_msg[INVALID_PE] = "Not correct number of player or exit!\n";
    print_errors(error, error_msg);
    destroy_all(data);
    exit(1);
}

/*void free_data(t_data *data)
{
    if (data)
	{
        if (data->map)
		{
            if (data->map)
			{
                for (int i = 0; data->map[i]; i++)
                    free(data->map[i]);
            }
        }
        if (data->file_name)
            free(data->file_name);
        data->file_name = NULL;
    }
    if (data)
        free(data);
}*/

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

void free_data(t_data *data)
{
    if (data)
    {
        if (data->map)
            free_map(data->map);
        if (data->map_copy)
            free_map(data->map_copy);
        if (data->file_name) {
            free(data->file_name);
            data->file_name = NULL;  // Importante: establecer a NULL después de liberar
        }
    }
}

int destroy_all(t_data *data)
{
    if (!data)
        return (0);
        
    // Liberar imágenes primero
    if (data->mlx)
    {
        if (data->back) mlx_destroy_image(data->mlx, data->back);
        if (data->wall) mlx_destroy_image(data->mlx, data->wall);
        if (data->player) mlx_destroy_image(data->mlx, data->player);
        if (data->exit) mlx_destroy_image(data->mlx, data->exit);
        if (data->obj) mlx_destroy_image(data->mlx, data->obj);
        
        if (data->window)
        {
            mlx_clear_window(data->mlx, data->window);
            mlx_destroy_window(data->mlx, data->window);
        }
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }
    
    // Liberar otros recursos
    free_data(data);
    
    free(data);
    exit(0);
    return (0);
}
