#include "../include/minirt.h"

t_ray	ray_primary(t_scene *scene, double u, double v)
{
	t_ray		ray;
	t_point3	p;

	ray.orig = scene->camera.orig;
	p = vminus(vplus(scene->viewport.left_upper, vmult(scene->camera.right, u)),
			vmult(scene->camera.up, v));
	// printf("%f %f %f\n", p.x, p.y, p.z);
	ray.dir = vunit(vminus(p, scene->camera.orig));
	return (ray);
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
	double	t;

	scene->rec = record_init();
	// 광선이 물체에 닿으면(광선과 물체가 만났고, 교점이 카메라 앞쪽이라면!)
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (color3(1, 0, 0));
	else
	{
		// t = 0.5 * (scene->ray.dir.y + 1.0);
		// return (vplus(vmult(color3(1, 1, 1), 1.0 - t),
		// 		vmult(color3(0.5, 0.7, 1.0), t)));
		t = 0.5 * (scene->ray.dir.y * 2 + 1.0);
	// (1-t) * 흰색 + t * 하늘색
		return (vplus(vmult(color3(1, 1, 1), 1.0 - t), vmult(color3(0.5, 0.7, 1.0), t)));
	}
	
}
