#include "../../include/minirt.h"

void	cam_left(t_scene *scene)
{
	scene->camera.dir = vmults(scene->camera.dir, 0.9);
	scene->camera.dir.x += 0.1;
	scene->camera.right = vunit(vcross(scene->camera.dir, vec3(0, 1, 0)));
	scene->camera.up = vunit(vcross(scene->camera.right, scene->camera.dir));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}

void	cam_right(t_scene *scene)
{
	scene->camera.dir = vmults(scene->camera.dir, 0.9);
	scene->camera.dir.x -= 0.1;
	scene->camera.right = vunit(vcross(scene->camera.dir, vec3(0, 1, 0)));
	scene->camera.up = vunit(vcross(scene->camera.right, scene->camera.dir));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}

void	cam_up(t_scene *scene)
{
	scene->camera.dir = vmults(scene->camera.dir, 0.9);
	scene->camera.right = vunit(vcross(scene->camera.dir, vec3(0, 1, 0)));
	scene->camera.up = vunit(vcross(scene->camera.right, scene->camera.dir));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}

void	cam_down(t_scene *scene)
{
	scene->camera.dir = vmults(scene->camera.dir, 0.9);
	scene->camera.dir.y -= 0.1;
	scene->camera.right = vunit(vcross(scene->camera.dir, vec3(0, 1, 0)));
	scene->camera.up = vunit(vcross(scene->camera.right, scene->camera.dir));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}
void	cam_zoomin(t_scene *scene)
{
	scene->camera.dir = vmults(scene->camera.dir, 0.9);
	scene->camera.dir.z -= 0.1;
	scene->camera.right = vunit(vcross(scene->camera.dir, vec3(0, 1, 0)));
	scene->camera.up = vunit(vcross(scene->camera.right, scene->camera.dir));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
	shoot_ray(scene, TRUE);
}

void	cam_zoomout(t_scene *scene)
{
	scene->camera.dir = vmults(scene->camera.dir, 0.9);
	scene->camera.dir.z += 0.1;
	scene->camera.right = vunit(vcross(scene->camera.dir, vec3(0, 1, 0)));
	scene->camera.up = vunit(vcross(scene->camera.right, scene->camera.dir));
	scene->viewport = set_viewport(scene->canvas, scene->camera);
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
	else if (keycode == 82)
		cam_zoomin(mlx_info->scene);
	else if (keycode == 83)
		cam_zoomout(mlx_info->scene);
	else if (keycode == 15)
		shoot_ray(mlx_info->scene, FALSE);
	return (0);
}
