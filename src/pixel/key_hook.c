/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:02:51 by seonmiki          #+#    #+#             */
/*   Updated: 2024/03/11 15:03:52 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	move_light(t_scene *scene)
{
	scene->lights->origin = scene->camera.orig;
	shoot_ray(scene, TRUE);
}

static void	cam_zoomin(t_scene *s)
{
	s->camera.orig = vplus(s->camera.orig, vmults(s->camera.dir, 10));
	s->viewport = set_viewport(s->canvas, s->camera);
	shoot_ray(s, TRUE);
}

static void	cam_zoomout(t_scene *s)
{
	s->camera.orig = vplus(s->camera.orig, vmults(s->camera.dir, -10));
	s->viewport = set_viewport(s->canvas, s->camera);
	shoot_ray(s, TRUE);
}

int	exit_hook(void)
{
	exit(0);
}

int	key_hook(int key, t_scene *scene)
{
	t_mlxinfo	*mlx_info;

	mlx_info = scene->mlxinfo;
	if (key == 53)
	{
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
		free_list(scene->world);
		exit(0);
	}
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		cam_dir_change(key, mlx_info);
	else if (key == 13 || key == 1 || key == 0 || key == 2)
		cam_move(key, mlx_info);
	else if (key == 83)
		cam_zoomin(mlx_info->scene);
	else if (key == 82)
		cam_zoomout(mlx_info->scene);
	else if (key == 37)
		move_light(mlx_info->scene);
	else if (key == 15)
		shoot_ray(mlx_info->scene, FALSE);
	return (0);
}
