#include "so_long.h"

void	handle_error(void)
{
	write(2, "Error\n", 6); // Obligatorio en so_long
	exit(EXIT_FAILURE);
}
 