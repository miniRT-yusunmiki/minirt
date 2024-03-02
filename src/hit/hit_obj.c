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

double	check_height(t_cylinder *cy, t_ray *ray, double t)
{
	t_vec3	x;
	double	h;

	x = vminus(ray->orig, cy->bottom_center);
	h = vdot(ray->dir, cy->normal) * t + vdot(x, cy->normal);
	if (0 <= h && h <= cy->height)
		return (h);
	return (-1);
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
	double	h;
	h = check_height(cy, ray, root);
	if (h == -1)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vminus(vplus(cy->bottom_center, vmults(cy->normal, h)), rec->p);
	set_face_normal(ray, rec);
	rec->color = cy->color;
	hit_cylinder_top(cy, ray, rec);
	return (TRUE);
}


t_bool	hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_cy;

	hit_cy = FALSE;
	if (hit_cylinder_top(cy, ray, rec))
		hit_cy = TRUE;
	if (hit_cylinder_bottom(cy, ray, rec))
		hit_cy = TRUE;
	if (hit_curved_surface(cy, ray, rec))
		hit_cy = TRUE;
	return (hit_cy);
}
