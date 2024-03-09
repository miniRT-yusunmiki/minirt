#include "../../include/minirt.h"

void	print_info(t_scene *scene)
{
	//ambient
	printf("ambient ret: %f %f %f\n", scene->ambient.x, scene->ambient.y, scene->ambient.z);

	//camera
	printf("camera.orig: %f %f %f\n", scene->camera.orig.x, scene->camera.orig.y, scene->camera.orig.z);
	printf("camera.dir: %f %f %f\n", scene->camera.dir.x, scene->camera.dir.y, scene->camera.dir.z);
	printf("camera.fov: %f\n", scene->camera.fov);

	//lights
	while (scene->lights)
	{
		printf("light.origin: %f %f %f\n", scene->lights->origin.x, scene->lights->origin.y, scene->lights->origin.z);
		printf("light.ratio: %f\n", scene->lights->ratio);
		printf("light.color: %f %f %f\n", scene->lights->color.x, scene->lights->color.y, scene->lights->color.z);
		scene->lights = scene->lights->next;
	}

	//object
	while (scene->world)
	{
		if (scene->world->type == SP)
		{
			t_sphere	*sp = scene->world->element;
			printf("sp.center: %f %f %f\n", sp->center.x, sp->center.y, sp->center.z);
			printf("sp.radius: %f\n", sp->radius);
			printf("sp.radius2: %f\n", sp->radius2);
			printf("sp.color: %f %f %f\n", sp->color.x, sp->color.y, sp->color.z);
		}
		else if (scene->world->type == PL)
		{
			t_plane	*pl = scene->world->element;
			printf("pl.point: %f %f %f\n", pl->point.x, pl->point.y, pl->point.z);
			printf("pl.normal: %f %f %f\n", pl->normal.x, pl->normal.y, pl->normal.z);
			printf("pl.color: %f %f %f\n", pl->color.x, pl->color.y, pl->color.z);
		}
		else if (scene->world->type == CY)
		{
			t_cylinder	*cy = scene->world->element;
			printf("cy.top_center: %f %f %f\n", cy->top_center.x, cy->top_center.y, cy->top_center.z);
			printf("cy.bottom_center: %f %f %f\n", cy->bottom_center.x, cy->bottom_center.y, cy->bottom_center.z);
			printf("cy.normal: %f %f %f\n", cy->normal.x, cy->normal.y, cy->normal.z);
			printf("cy.radius: %f\n", cy->radius);
			printf("cy.height: %f\n", cy->height);
			printf("cy.color: %f %f %f\n", cy->color.x, cy->color.y, cy->color.z);
		}
		printf("id: %d\n",scene->world->idx);
		scene->world = scene->world->next;
	}

}