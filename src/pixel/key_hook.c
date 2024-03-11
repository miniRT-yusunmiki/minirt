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

int	key_hook(int keycode, t_scene *scene)
{
	t_mlxinfo	*mlx_info;

	mlx_info = scene->mlxinfo;
	if (keycode == 53)
	{
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
		free_list(scene->world);
		exit(0);
	}
	else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		cam_dir_change(keycode, mlx_info);
	else if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		cam_move(keycode, mlx_info);
	else if (keycode == 83)
		cam_zoomin(mlx_info->scene);
	else if (keycode == 82)
		cam_zoomout(mlx_info->scene);
	else if (keycode == 37)
		move_light(mlx_info->scene);
	else if (keycode == 15)
		shoot_ray(mlx_info->scene, FALSE);
	return (0);
}
