#include "../include/minirt.h"

t_bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere(world->element, ray, rec);
	// if (world->type == PL)
	// 	hit_result = hit_plane(world, ray, rec);
	//if (world->type == CYL)
	//  hit_result = hit_cylinder(world, ray, rec);
	return (hit_result);
}

t_bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool		hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}
