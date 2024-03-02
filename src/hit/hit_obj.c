#include "../../include/minirt.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	if (rec->front_face == FALSE)
		rec->normal = vmults(rec->normal, -1);
}

t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	double	tca;
	double	thc;
	double	d;
	double	t;
	t_vec3	L;
 
	L = vminus(sp->center, ray->orig);
	tca = vdot(ray->dir, L);
	if (tca < 0)
		return (FALSE);
	d = sqrt(vlength2(L) - pow(tca, 2));
	if (d > sp->radius)
		return (FALSE);
	thc = sqrt(sp->radius2 - pow(d, 2));
	t = tca - thc;
	if (t < rec->tmin || t > rec->tmax)
		return (FALSE);
	rec->t = tca - thc;
	rec->p = ray_at(ray, t);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	rec->color = sp->color;
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec)
{
	double	denom;
	double	t;

	denom = vdot(ray->dir, pl->normal);
    if (fabs(denom) < EPSILON)
		return (FALSE);
	t = vdot(vminus(pl->point, ray->orig), pl->normal) / denom;
	if (t < rec->tmin || rec->tmax < t)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->normal = pl->normal;
	rec->color = pl->color;
	set_face_normal(ray, rec);
	return (TRUE);
}
