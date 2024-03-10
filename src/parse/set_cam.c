#include "../../include/minirt.h"

t_color3	set_ambient(char **elem)
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
	return (vmults(color, ratio));
}

t_camera	set_camera(char **elem)
{
	t_camera	camera;

	if (count_elem(elem) != 4)
	{
		write(2, "wrong camera info\n", 19);
		exit(1);
	}
	camera.orig = get_point(elem[1]);
	camera.dir = vunit(get_vector(elem[2]));
	camera.fov = ft_atof(elem[3]);
	if (!(0 <= camera.fov && camera.fov <= 180))
	{
		write(2, "wrong camera info\n", 19);
		exit(1);
	}
	camera.right = vunit(vcross(camera.dir, vec3(0, 1, 0)));
	camera.up = vunit(vcross(camera.right, camera.dir));
	return (camera);
}

t_viewport	set_viewport(t_canvas canvas, t_camera cam)
{
	t_viewport	vp;
	t_point3	focus;
	t_point3	focus_left;

	vp.height = 2.0;
	vp.width = vp.height * canvas.aspect_ratio;
	vp.focal_len = (vp.width / 2) / tan((cam.fov * 0.5) * M_PI / 180);
	focus = vplus(cam.orig, vmults(cam.dir, vp.focal_len));
	focus_left = vminus(focus, vmults(cam.right, (vp.width * 0.5)));
	vp.left_upper = vplus(focus_left, vmults(cam.up, (vp.height * 0.5)));
	return (vp);
}

t_light	*set_light(char **elem)
{
	t_light	*light;

	if (count_elem(elem) != 4)
	{
		write(2, "wrong light info\n", 18);
		exit(1);
	}
	light = (t_light *)malloc(sizeof(t_light));
	light->origin = get_point(elem[1]);
	light->ratio = ft_atof(elem[2]);
	if (!(0.0 <= light->ratio && light->ratio <= 1.0))
	{
		write(2, "wrong light info\n", 18);
		exit(1);
	}
	light->color = get_color(elem[3]);
	light->next = NULL;
	return (light);
}
