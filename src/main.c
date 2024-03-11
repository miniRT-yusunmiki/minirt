/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusung <yusung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:47:19 by yusung            #+#    #+#             */
/*   Updated: 2024/03/11 15:47:23 by yusung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int ac, char **av)
{
	t_scene	*scene;

	check_arg(ac, av);
	scene = set_scene(av[1]);
	shoot_ray(scene, FALSE);
	mlx_key_hook(scene->mlxinfo->win_ptr, key_hook, scene);
	mlx_hook(scene->mlxinfo->win_ptr, 17, 0, exit_hook, 0);
	mlx_loop(scene->mlxinfo->mlx_ptr);
	return (0);
}
