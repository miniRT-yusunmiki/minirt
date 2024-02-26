#include "../include/minirt.h"

t_bool	is_rt_file(char *arg1)
{
	int	arg_len;

	arg_len = ft_strlen(arg1);
	if (ft_strncmp(&arg1[arg_len - 3], ".rt", 4))
		return (FALSE);
	return (TRUE);
}

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Incorrect number of arguments\n", 31);
		exit(1);
	}
	if (!is_rt_file(argv[1]))
	{
		write(2, "The first argument must be a file with .rt extension.\n", 54);
		exit(1);
	}
}
