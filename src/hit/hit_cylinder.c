#include "../../include/minirt.h"

t_bool	in_height_range(t_cylinder *cy, t_ray *ray, t_hit_record *rec, double t)
{
	t_vec3	x;
	double	h;

	x = vminus(ray->orig, cy->bottom_center);
	h = vdot(ray->dir, cy->normal) * t + vdot(x, cy->normal);
	if (0 <= h && h <= cy->height)
    {
    	rec->normal = vminus(vplus(cy->bottom_center, vmults(cy->normal, h)), rec->p);
        return (TRUE);
    }
	return (FALSE);
}

t_bool	hit_cylinder_top(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
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

t_bool	hit_cylinder_bottom(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_plane	bottom;
	t_hit_record	tmp_rec;

	bottom.normal = cy->normal;
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
			rec->normal = tmp_rec.normal;
			rec->color = tmp_rec.color;
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	hit_curved_surface(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	double	a;
	double	half_b;
	double	c;
	t_vec3	x;
	double	discriminant;
	double	sqrtd;
	double	root;

	x = vminus(ray->orig, cy->bottom_center);
	a = vlength2(ray->dir) - pow(vdot(ray->dir, cy->normal), 2);
	half_b = vdot(ray->dir, x) - vdot(ray->dir, cy->normal) * vdot(x, cy->normal);
	c = vlength2(x) - pow(vdot(x, cy->normal), 2) - pow(cy->radius, 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || root > rec->tmax)
			return (FALSE);
	}
	rec->p = ray_at(ray, root);
	if (!in_height_range(cy, ray, rec, root))
		return (FALSE);
	rec->t = root;
	set_face_normal(ray, rec);
	rec->color = cy->color;
	return (TRUE);
}

void	copy_rec(t_hit_record *dest, t_hit_record *src)
{
	dest->color = src->color;
	dest->front_face = src->front_face;
	dest->p = src->p;
	dest->t = src->t;
	dest->tmax = src->tmax;
	dest->tmin = src->tmin;
}

t_bool	hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_cy;
	t_hit_record	cy_rec;

	hit_cy = FALSE;
	cy_rec.tmax = rec->tmax;
	cy_rec.tmin = rec->tmin;
	if (hit_cylinder_top(cy, ray, &cy_rec))
	{
		hit_cy = TRUE;
		copy_rec(rec, &cy_rec);
	}
	if (hit_cylinder_bottom(cy, ray, &cy_rec))
	{
		hit_cy = TRUE;
		copy_rec(rec, &cy_rec);
	}
	if (hit_curved_surface(cy, ray, &cy_rec))
	{
		hit_cy = TRUE;
		copy_rec(rec, &cy_rec);
	}
	return (hit_cy);
}
