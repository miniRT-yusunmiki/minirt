/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusung <yusung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:46:20 by yusung            #+#    #+#             */
/*   Updated: 2024/03/11 15:46:21 by yusung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

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
		write(2, "Error\nIncorrect number of arguments\n", 37);
		exit(1);
	}
	if (!is_rt_file(argv[1]))
	{
		write(2, "Error\nThe first argument must be a .rt file\n", 44);
		exit(1);
	}
}
