#include "../../include/minirt.h"

t_bool	in_shadow(t_scene *scene, t_light *light, t_hit_record *rec)
{
	double			light_len;
	t_ray			light_ray;
	t_hit_record	light_rec;

	light_len = vlength(vminus(light->origin, rec->p));
	light_ray.orig = rec->p;
	light_ray.dir = vunit(rec->light_dir);
	light_rec.tmin = EPSILON;
	light_rec.tmax = light_len;
	if (hit(scene->world, &light_ray, &light_rec, TRUE))
	{
		// if (light_rec.idx != rec->idx)
		// if (vdot(light_ray.dir, rec->p) < 0)
			return (TRUE);
	}
	return (FALSE);
}
