#include "so_long.h"

int main(int argc, char **argv)
{
    t_data *data = NULL;
    
    if (argc != 2)
        handle_error(PARAMETROS, NULL);
    
    data = malloc(sizeof(t_data));
    if (!data)
        handle_error(MALLOCERROR, NULL);
    ft_memset(data, 0, sizeof(t_data));
    
    if (ft_init(data, argv) != 0)
    {
        destroy_all(data);
        return (1);
    }
    
    game_init(data);
    destroy_all(data);  // Asegurar que siempre se llame al salir
    return (0);
}
