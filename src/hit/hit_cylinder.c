#include "../../include/minirt.h"

t_bool	hit_cy_top(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_plane			top;
	t_hit_record	tmp_rec;

	top.normal = cy->normal;
	top.point = cy->top_center;
	top.color = cy->color;
	tmp_rec.tmax = rec->tmax;
	tmp_rec.tmin = rec->tmin;
	if (hit_plane(&top, ray, &tmp_rec))
	{
		if (vlength(vminus(tmp_rec.p, cy->top_center)) <= cy->radius)
		{
			rec->t = tmp_rec.t;
			rec->p = tmp_rec.p;
			rec->normal = tmp_rec.normal;
			rec->color = tmp_rec.color;
			rec->tmax = rec->t;
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	hit_cy_bottom(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_plane			bottom;
	t_hit_record	tmp_rec;

	bottom.normal = vunit(vmults(cy->normal, -1));
	bottom.point = cy->bottom_center;
	bottom.color = cy->color;
	tmp_rec.tmax = rec->tmax;
	tmp_rec.tmin = rec->tmin;
	if (hit_plane(&bottom, ray, &tmp_rec))
	{
		if (vlength(vminus(tmp_rec.p, cy->bottom_center)) <= cy->radius)
		{
			rec->t = tmp_rec.t;
			rec->p = tmp_rec.p;
			rec->normal = vunit(tmp_rec.normal);
			rec->color = tmp_rec.color;
			rec->tmax = rec->t;
			return (TRUE);
		}
	}
	return (FALSE);
}

double	in_height_range(t_cylinder *cy, t_ray *ray, double t)
{
	double	h;

	h = vdot(ray->orig, cy->normal) + (t * vdot(ray->dir, cy->normal)) - vdot(cy->bottom_center, cy->normal);
	return (h);
}

t_bool	get_root(t_cylinder *cy, t_ray *ray, t_formula *fm)
{
	t_vec3	oc;

	oc = vminus(ray->orig, cy->bottom_center);
	fm->a = 1 - pow(vdot(ray->dir, cy->normal), 2);
	fm->half_b = vdot(ray->dir, oc) - vdot(ray->dir, cy->normal) * vdot(oc, cy->normal);
	fm->c = vlength2(oc) - pow(vdot(oc, cy->normal), 2) - pow(cy->radius, 2);
	fm->discriminant = pow(fm->half_b, 2) - fm->a * fm->c;
	if (fm->discriminant < 0)
		return (FALSE);
	fm->sqrtd = sqrt(fm->discriminant);
	fm->root = ((fm->half_b * -1) - fm->sqrtd) / fm->a;
	return (TRUE);
}

t_bool	hit_curved_surface(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_formula	fm;
	double		h;

	if (get_root(cy, ray, &fm) == FALSE)
		return (FALSE);
	if (fm.root <= rec->tmin || fm.root >= rec->tmax)
	{
		fm.root = ((fm.half_b * -1) + fm.sqrtd) / fm.a;
		if (fm.root <= rec->tmin || fm.root >= rec->tmax)
			return (FALSE);
	}
	h = in_height_range(cy, ray, fm.root);
	if (h < EPSILON || h > cy->height)
		return (FALSE);
	rec->t = fm.root;
	rec->p = ray_at(ray, fm.root);
	rec->normal = vunit(vminus(rec->p, vplus(cy->bottom_center, vmults(cy->normal, h))));
	rec->color = cy->color;
	rec->tmax = rec->t;
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_cy;

	hit_cy = FALSE;
	if (hit_cy_top(cy, ray, rec))
		hit_cy = TRUE;
	if (hit_cy_bottom(cy, ray, rec))
		hit_cy = TRUE;
	if (hit_curved_surface(cy, ray, rec))
		hit_cy = TRUE;
	return (hit_cy);
}
