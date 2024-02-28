#include "../include/minirt.h"

t_ray	ray_primary(t_scene *scene, double u, double v)
{
	t_ray		ray;
	t_point3	p;

	ray.orig = scene->camera.orig;
	p = vminus(vplus(scene->viewport.left_upper, vmult(scene->camera.right, u)),
			vmult(scene->camera.up, v));
	ray.dir = vunit(vminus(p, scene->camera.orig));
	// printf("ray.orig: %f, %f, %f\n", ray.orig.x, ray.orig.y, ray.orig.z);
	// printf("ray.dir: %f, %f, %f\n", ray.dir.x, ray.dir.y, ray.dir.z);
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3 at;

	at = vplus(ray->orig, vmult(ray->dir, t));
	return (at);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_color3	ray_color(t_scene *scene)
{
	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_light(scene));
	return (color3(0,0,0));
}