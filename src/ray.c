#include "../include/minirt.h"

t_ray	ray_primary(t_scene *scene, double u, double v)
{
	t_ray		ray;
	t_point3	p;

	ray.orig = scene->camera.orig;
	p = vminus(vplus(scene->viewport.left_upper, vmult(scene->camera.right, u)),
			vmult(scene->camera.up, v));
	ray.dir = vunit(vminus(p, scene->camera.orig));
	return (ray);
}

t_color3	ray_color(t_scene *scene)
{
	double	t;

	t = 0.5 * (scene->ray.dir.y * 2 + 1.0);
	// (1-t) * 흰색 + t * 하늘색
	return (vplus(vmult(color3(1, 1, 1), 1.0 - t), vmult(color3(0.5, 0.7, 1.0), t)));
}
