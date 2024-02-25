#include "../include/minirt.h"

t_color3	parse_ambient_info(char **elem)
{
	double		ratio;
	t_color3	color;

	if (count_elem(elem) != 3)
	{
		write(2, "wrong ambient info\n", 20);
		exit(1);
	}
	ratio = ft_atof(elem[1]);
	if (!(0.0 <= ratio && ratio <= 1.0))
	{
		write(2, "wrong ambient info\n", 20);
		exit(1);
	}
	color = get_color(elem[2]);
	return (vmult(color, ratio));
}

t_camera	parse_camera_info(char **elem)
{
	t_camera	cam;

	if (count_elem(elem) != 4)
	{
		write(2, "wrong camera info\n", 20);
		exit(1);
	}
	cam.origin = get_point(elem[1]);
	cam.vector = get_vector(elem[2]);
	cam.pov = ft_atof(elem[3]);
	if (!(0 <= cam.pov && cam.pov <= 180))
	{
		write(2, "wrong camera info\n", 20);
		exit(1);
	}
	// viewport 정보도 추가해주어야함
	return (cam);
}

t_light	*parse_light_info(char **elem)
{
	t_light	*light;

	if (count_elem(elem) != 4)
	{
		write(2, "wrong light info\n", 20);
		exit(1);
	}
	light = (t_light *)malloc(sizeof(t_light));
	light->origin = get_point(elem[1]);
	light->ratio = ft_atof(elem[2]);
	if (!(0.0 <= light->ratio && light->ratio <= 1.0))
	{
		write(2, "wrong light info\n", 20);
		exit(1);
	}
	light->color = get_color(elem[3]);
	light->next = NULL;
	return (light);
}
