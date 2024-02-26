#include "../../include/minirt.h"

t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	double	tca;
	double	thc;
	double	d;
	t_vec3	L;
 
	L = vminus(sp->center, ray->orig);
	// printf("L: %f, ", vlength(L));
	tca = vdot(ray->dir, L);
	if (tca < 0)
	{
		// printf("\n");
		return (FALSE);
	}
	d = sqrt(vlength2(L) - pow(tca, 2));
	// printf("d: %f, ", d);
	if (d > sp->radius)
	{
		// printf("\n");
		return (FALSE);
	}
	thc = sqrt(sp->radius2 - pow(d, 2));
	// printf("thc: %f\n", thc);
	rec->t = tca - thc;
	rec->p = ray_at(ray, rec->t);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	rec->color = sp->color;
	return (TRUE);
}
