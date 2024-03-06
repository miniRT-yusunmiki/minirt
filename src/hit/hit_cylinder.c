#include "../../include/minirt.h"

t_bool	hit_cy_top(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_plane	top;
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
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	hit_cy_bottom(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_plane	top;
	t_hit_record	tmp_rec;

	top.normal = vmults(cy->normal, 1);
	top.point = cy->bottom_center;
	top.color = cy->color;
	tmp_rec.tmax = rec->tmax;
	tmp_rec.tmin = rec->tmin;
	if (hit_plane(&top, ray, &tmp_rec))
	{
		if (vlength(vminus(tmp_rec.p, cy->bottom_center)) <= cy->radius)
		{
			rec->t = tmp_rec.t;
			rec->p = tmp_rec.p;
			rec->normal = tmp_rec.normal;
			rec->color = tmp_rec.color;
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	in_height_range(t_cylinder *cy, t_ray *ray, t_hit_record *rec, double t)
{
	double	h;

	h = vdot(ray->orig, cy->normal) + (t * vdot(ray->dir, cy->normal)) - vdot(cy->bottom_center, cy->normal);
	if (0 <= h && h <= cy->height)
    {
    	rec->normal = vplus(vplus(cy->bottom_center, vmults(cy->normal, h)), ray_at(ray, t));
        return (TRUE);
    }
	return (FALSE);
}

t_bool	hit_curved_surface(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	double	a;
	double	half_b;
	double	c;
	t_vec3	oc;
	double	discriminant;
	double	sqrtd;
	double	root;

	oc = vminus(ray->orig, cy->bottom_center);
	a = vlength2(ray->dir) - pow(vdot(ray->dir, cy->normal), 2);
	half_b = vdot(ray->dir, oc) - vdot(ray->dir, cy->normal) * vdot(oc, cy->normal);
	c = vlength2(oc) - pow(vdot(oc, cy->normal), 2) - pow(cy->radius, 2);
	discriminant = pow(half_b, 2) - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = ((half_b * -1) - sqrtd) / a;
	if (root < rec->tmin || root > rec->tmax)
	{
		root = ((half_b * -1) - sqrtd) / a;
		if (root < rec->tmin || root > rec->tmax)
			return (FALSE);
	}
	if (!in_height_range(cy, ray, rec, root))
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->color = cy->color;
	// set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_cy;

	hit_cy = FALSE;
	if (hit_curved_surface(cy, ray, rec))
		hit_cy = TRUE;
	if (hit_cy_top(cy, ray, rec))
		hit_cy = TRUE;
	if (hit_cy_bottom(cy, ray, rec))
		hit_cy = TRUE;
	return (hit_cy);
}
