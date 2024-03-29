/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_dir_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusung <yusung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:02:07 by seonmiki          #+#    #+#             */
/*   Updated: 2024/03/11 20:24:23 by yusung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	cam_left(t_scene *s)
{
	s->camera.dir = vunit(vplus(s->camera.dir, vmults(s->camera.right, -0.1)));
	if (s->camera.dir.y == 1.0 || s->camera.dir.y == -1.0)
		s->camera.right = vec3(1, 0, 0);
	else
		s->camera.right = vunit(vcross(s->camera.dir, vec3(0, 1, 0)));
	s->camera.up = vunit(vcross(s->camera.right, s->camera.dir));
	s->viewport = set_viewport(s->canvas, s->camera);
	shoot_ray(s, TRUE);
}

static void	cam_right(t_scene *s)
{
	s->camera.dir = vunit(vplus(s->camera.dir, vmults(s->camera.right, 0.1)));
	if (s->camera.dir.y == 1.0 || s->camera.dir.y == -1.0)
		s->camera.right = vec3(1, 0, 0);
	else
		s->camera.right = vunit(vcross(s->camera.dir, vec3(0, 1, 0)));
	s->camera.up = vunit(vcross(s->camera.right, s->camera.dir));
	s->viewport = set_viewport(s->canvas, s->camera);
	shoot_ray(s, TRUE);
}

static void	cam_up(t_scene *s)
{
	s->camera.dir = vunit(vplus(s->camera.dir, vmults(s->camera.up, 0.1)));
	if (s->camera.dir.y == 1.0 || s->camera.dir.y == -1.0)
		s->camera.right = vec3(1, 0, 0);
	else
		s->camera.right = vunit(vcross(s->camera.dir, vec3(0, 1, 0)));
	s->camera.up = vunit(vcross(s->camera.right, s->camera.dir));
	s->viewport = set_viewport(s->canvas, s->camera);
	shoot_ray(s, TRUE);
}

static void	cam_down(t_scene *s)
{
	s->camera.dir = vunit(vplus(s->camera.dir, vmults(s->camera.up, -0.1)));
	if (s->camera.dir.y == 1.0 || s->camera.dir.y == -1.0)
		s->camera.right = vec3(1, 0, 0);
	else
		s->camera.right = vunit(vcross(s->camera.dir, vec3(0, 1, 0)));
	s->camera.up = vunit(vcross(s->camera.right, s->camera.dir));
	s->viewport = set_viewport(s->canvas, s->camera);
	shoot_ray(s, TRUE);
}

void	cam_dir_change(int keycode, t_mlxinfo *mlx_info)
{
	if (keycode == 123)
		cam_left(mlx_info->scene);
	else if (keycode == 124)
		cam_right(mlx_info->scene);
	else if (keycode == 126)
		cam_up(mlx_info->scene);
	else if (keycode == 125)
		cam_down(mlx_info->scene);
}
