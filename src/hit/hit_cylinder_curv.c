/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_curv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:57:58 by seonmiki          #+#    #+#             */
/*   Updated: 2024/03/11 14:59:26 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double	in_height_range(t_cylinder *cy, t_ray *ray, double t)
{
	double	h;

	h = vdot(ray->orig, cy->normal) + (t * vdot(ray->dir, cy->normal))
		- vdot(cy->bottom_center, cy->normal);
	return (h);
}

t_bool	get_root(t_cylinder *cy, t_ray *ray, t_formula *fm)
{
	t_vec3	oc;

	oc = vminus(ray->orig, cy->bottom_center);
	fm->a = 1 - pow(vdot(ray->dir, cy->normal), 2);
	fm->half_b = vdot(ray->dir, oc) - vdot(ray->dir, cy->normal)
		* vdot(oc, cy->normal);
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
	if (fm.root < rec->tmin || fm.root >= rec->tmax - EPSILON)
	{
		fm.root = ((fm.half_b * -1) + fm.sqrtd) / fm.a;
		if (fm.root < rec->tmin || fm.root >= rec->tmax - EPSILON)
			return (FALSE);
	}
	h = in_height_range(cy, ray, fm.root);
	if (h < EPSILON || h > cy->height)
		return (FALSE);
	rec->t = fm.root;
	rec->p = ray_at(ray, fm.root);
	rec->normal = vunit(vminus(rec->p, vplus(cy->bottom_center,
					vmults(cy->normal, h))));
	rec->color = cy->color;
	rec->tmax = rec->t;
	set_face_normal(ray, rec);
	return (TRUE);
}
