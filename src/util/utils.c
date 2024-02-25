#include "../../include/minirt.h"

int	count_elem(char **elem)
{
	int	cnt;

	cnt = 0;
	while (elem && elem[cnt])
		cnt++;
	return (cnt);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (i < count_elem(arr))
		free(arr[i++]);
	free(arr);
}
