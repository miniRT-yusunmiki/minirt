/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:55:57 by seonmiki          #+#    #+#             */
/*   Updated: 2024/03/11 14:58:52 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
