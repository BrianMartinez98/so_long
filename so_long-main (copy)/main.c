#include "so_long.h"

int main(int argc, char **argv)
{
	t_data	*data = {0};

	if (argc != 2)
		handle_error(PARAMETROS, data);
	data = malloc(sizeof(t_data));
	if (!data)
		handle_error(MALLOCERROR, data);
	ft_init(data, argv);
	game_init(data);
	destroy_all(data);
	return (0);
}
