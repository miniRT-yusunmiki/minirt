#include "../../include/minirt.h"

t_sphere	*set_sphere(char **elem)
{
	t_sphere	*sphere;
	double		diameter;

	if (count_elem(elem) != 4)
	{
		write(2, "wrong sphere info\n", 19);
		exit(1);
	}
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->center = get_point(elem[1]);
	diameter = ft_atof(elem[2]);
	sphere->radius = diameter / 2;
	sphere->radius2 = pow(sphere->radius, 2);
	sphere->color = get_color(elem[3]);
	return (sphere);
}

t_plane	*set_plane(char **elem)
{
	t_plane	*plane;

	if (count_elem(elem) != 4)
	{
		write(2, "wrong plane info\n", 18);
		exit(1);
	}
	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->point = get_point(elem[1]);
	plane->normal = get_vector(elem[2]);
	plane->color = get_color(elem[3]);
	return (plane);
}

t_cylinder	*set_cylinder(char **elem)
{
	t_cylinder	*cylinder;

	if (count_elem(elem) != 6)
	{
		write(2, "wrong cylinder info\n", 21);
		exit(1);
	}
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	cylinder->center = get_point(elem[1]);
	cylinder->normal = get_vector(elem[2]);
	cylinder->diameter = ft_atof(elem[3]);
	cylinder->height = ft_atof(elem[4]);
	cylinder->color = get_color(elem[5]);
	return (cylinder);
}
