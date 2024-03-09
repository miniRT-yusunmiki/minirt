#include "../../include/minirt.h"

t_bool	in_shadow(t_scene *scene, t_light *light, t_hit_record *rec)
{
	double			light_len;
	t_ray			light_ray;
	t_hit_record	light_rec;

	light_len = vlength(rec->light_dir);
	light_ray.orig = rec->p;
	light_ray.dir = vunit(vminus(light->origin, light_ray.orig));
	light_rec.tmin = EPSILON;
	light_rec.tmax = light_len - EPSILON;
	if (hit(scene->world, &light_ray, &light_rec))
		return (TRUE);
	return (FALSE);
}
