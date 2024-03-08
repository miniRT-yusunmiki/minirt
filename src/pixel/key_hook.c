#include "../../include/minirt.h"

void	cam_left(t_scene *scene)
{
	scene->camera.dir = vunit(vplus(scene->camera.dir, vmults(scene->camera.right, -0.1)));
	scene->camera.right = vunit(vcross(scene->camera.dir, vec3(0, 1, 0)));
	scene->camera.up = vunit(vcross(scene->camera.right, scene->camera.dir));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}

void	cam_right(t_scene *scene)
{

	scene->camera.dir = vunit(vplus(scene->camera.dir, vmults(scene->camera.right, 0.1)));
	scene->camera.right = vunit(vcross(scene->camera.dir, vec3(0, 1, 0)));
	scene->camera.up = vunit(vcross(scene->camera.right, scene->camera.dir));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}

void	cam_up(t_scene *scene)
{
	scene->camera.dir = vunit(vplus(scene->camera.dir, vmults(scene->camera.up, 0.1)));
	scene->camera.right = vunit(vcross(scene->camera.dir, vec3(0, 1, 0)));
	scene->camera.up = vunit(vcross(scene->camera.right, scene->camera.dir));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}

void	cam_down(t_scene *scene)
{
	scene->camera.dir = vunit(vplus(scene->camera.dir, vmults(scene->camera.up, -0.1)));
	scene->camera.right = vunit(vcross(scene->camera.dir, vec3(0, 1, 0)));
	scene->camera.up = vunit(vcross(scene->camera.right, scene->camera.dir));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}
void	cam_move_up(t_scene *scene)
{
	scene->camera.orig = vplus(scene->camera.orig, vmults(scene->camera.dir, 10));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}

void	cam_move_down(t_scene *scene)
{
	scene->camera.orig = vplus(scene->camera.orig, vmults(scene->camera.dir, -10));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}
void	cam_move_left(t_scene *scene)
{
	scene->camera.orig = vplus(scene->camera.orig, vmults(scene->camera.right, -10));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}

void	cam_move_right(t_scene *scene)
{
	scene->camera.orig = vplus(scene->camera.orig, vmults(scene->camera.right, 10));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}

void	move_light(t_scene *scene)
{
	scene->lights->origin = scene->camera.orig;
	shoot_ray(scene, TRUE);
}

int	key_hook(int keycode, t_mlxinfo *mlx_info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
		exit(0);
	}
	else if (keycode == 123)
		cam_left(mlx_info->scene);
	else if (keycode == 124)
		cam_right(mlx_info->scene);
	else if (keycode == 126)
		cam_up(mlx_info->scene);
	else if (keycode == 125)
		cam_down(mlx_info->scene);
	else if (keycode == 13) //1
		cam_move_up(mlx_info->scene);
	else if (keycode == 1) //0
		cam_move_down(mlx_info->scene);
	else if (keycode == 0) //1
		cam_move_left(mlx_info->scene);
	else if (keycode == 2) //0
		cam_move_right(mlx_info->scene);
	else if (keycode == 37) //0
		move_light(mlx_info->scene);
	else if (keycode == 15) //r
		shoot_ray(mlx_info->scene, FALSE);
	return (0);
}
