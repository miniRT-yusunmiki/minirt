/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:59:35 by seonmiki          #+#    #+#             */
/*   Updated: 2024/03/11 15:00:04 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec)
{
	double	denom;
	double	t;

	denom = vdot(ray->dir, pl->normal);
	if (fabs(denom) < EPSILON)
		return (FALSE);
	t = vdot(vminus(pl->point, ray->orig), pl->normal) / denom;
	if (t < rec->tmin || t >= rec->tmax - EPSILON)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->normal = pl->normal;
	rec->color = pl->color;
	set_face_normal(ray, rec);
	return (TRUE);
}
