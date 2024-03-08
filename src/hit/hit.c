#include "../../include/minirt.h"

t_bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool		hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec; // temp_rec의 tmin, tmax 값 초기화를 위해
	hit_anything = FALSE;
	while(world)
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

t_bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere(world->element, ray, rec);
	else if (world->type == PL)
		hit_result = hit_plane(world->element, ray, rec);
	else if (world->type == CY)
		hit_result = hit_cylinder(world->element, ray, rec);
	return (hit_result);
}

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	if (rec->front_face == FALSE)
		rec->normal = vmults(rec->normal, -1);
}
