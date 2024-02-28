#include "../../include/minirt.h"

t_color3	get_diffuse(t_hit_record *rec, t_light *light)
{
	t_color3	diffuse;
	double		cos;

	rec->light_dir = vminus(light->origin, rec->p);
	cos = fmax(vdot(vunit(rec->normal), vunit(rec->light_dir)), 0.0);
	diffuse = vmults(vmults(light->color, light->ratio), cos);
	return (diffuse);
}
