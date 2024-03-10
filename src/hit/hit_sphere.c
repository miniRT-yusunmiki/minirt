#include "../../include/minirt.h"

t_bool	hit_sphere(t_object *obj, t_ray *ray, t_hit_record *rec, t_bool shadow)
{
	double	tca;
	double	thc;
	double	d;
	double	t;
	t_vec3	L;
	t_sphere *sp;
 
	sp = obj->element;
	L = vminus(sp->center, ray->orig);
	tca = vdot(ray->dir, L);
	if (tca < 0)
		return (FALSE);
	d = sqrt(vlength2(L) - pow(tca, 2));
	if (d > sp->radius)
		return (FALSE);
	thc = sqrt(sp->radius2 - pow(d, 2));
	t = tca - thc;
	if (t < rec->tmin || t >= rec->tmax)
	{
		t = tca + thc;
		if (t < rec->tmin || t >= rec->tmax)
			return (FALSE);
	}
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->normal = vunit(vminus(rec->p, sp->center));
	rec->color = sp->color;
	rec->idx = obj->idx;
	(void)shadow;
	// if (shadow == FALSE)
		set_face_normal(ray, rec);
	return (TRUE);
}
