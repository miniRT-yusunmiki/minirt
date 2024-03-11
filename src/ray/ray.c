/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:04:29 by seonmiki          #+#    #+#             */
/*   Updated: 2024/03/11 15:05:21 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray	ray_primary(t_scene *scene, double u, double v)
{
	t_ray		ray;
	t_point3	p;

	ray.orig = scene->camera.orig;
	p = vminus(vplus(scene->viewport.left_upper,
				vmults(scene->camera.right, u)),
			vmults(scene->camera.up, v));
	ray.dir = vunit(vminus(p, scene->camera.orig));
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vplus(ray->orig, vmults(ray->dir, t));
	return (at);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_color3	ray_color(t_scene *scene)
{
	t_color3	diffuse;
	t_color3	total;

	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
	{
		diffuse = get_diffuse(&scene->rec, scene->lights);
		total = vplus(diffuse, scene->ambient);
		if (in_shadow(scene, scene->lights, &scene->rec))
			return (vmultv(scene->rec.color, scene->ambient));
		return (vmin(vmultv(scene->rec.color, total), vec3(1, 1, 1)));
	}
	return (vmin(vmultv(vec3(1, 1, 1), scene->ambient), vec3(1, 1, 1)));
}
