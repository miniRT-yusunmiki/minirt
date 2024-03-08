#include "../../include/minirt.h"

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
	rec->normal = vunit(pl->normal);
	rec->color = pl->color;
	set_face_normal(ray, rec);
	return (TRUE);
}
