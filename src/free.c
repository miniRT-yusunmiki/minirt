#include "../include/minirt.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (i < count_elem(arr))
		free(arr[i++]);
	free(arr);
}
