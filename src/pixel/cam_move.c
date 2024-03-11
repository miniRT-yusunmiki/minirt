/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:02:29 by seonmiki          #+#    #+#             */
/*   Updated: 2024/03/11 15:02:40 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	cam_move_up(t_scene *s)
{
	s->camera.orig = vplus(s->camera.orig, vmults(s->camera.up, 10));
	s->viewport = set_viewport(s->canvas, s->camera);
	shoot_ray(s, TRUE);
}

static void	cam_move_down(t_scene *s)
{
	s->camera.orig = vplus(s->camera.orig, vmults(s->camera.up, -10));
	s->viewport = set_viewport(s->canvas, s->camera);
	shoot_ray(s, TRUE);
}

static void	cam_move_left(t_scene *s)
{
	s->camera.orig = vplus(s->camera.orig, vmults(s->camera.right, -10));
	s->viewport = set_viewport(s->canvas, s->camera);
	shoot_ray(s, TRUE);
}

static void	cam_move_right(t_scene *s)
{
	s->camera.orig = vplus(s->camera.orig, vmults(s->camera.right, 10));
	s->viewport = set_viewport(s->canvas, s->camera);
	shoot_ray(s, TRUE);
}

void	cam_move(int keycode, t_mlxinfo *mlx_info)
{
	if (keycode == 13)
		cam_move_up(mlx_info->scene);
	else if (keycode == 1)
		cam_move_down(mlx_info->scene);
	else if (keycode == 0)
		cam_move_left(mlx_info->scene);
	else if (keycode == 2)
		cam_move_right(mlx_info->scene);
}
