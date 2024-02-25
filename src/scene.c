#include "../include/minirt.h"

t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_mlxinfo	*mlxinfo_init(int width, int height)
{
	t_mlxinfo	*m;

	m = (t_mlxinfo *)malloc(sizeof(t_mlxinfo));
	if (!m)
		return (NULL);
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, width, height, "miniRT");
	m->img_ptr = mlx_new_image(m->mlx_ptr, width, height);
	m->img_addr = mlx_get_data_addr(m->img_ptr, &m->pbits, &m->len, &m->endian);
	return (m);
}

t_scene	*set_scene(char *file_name)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->canvas = canvas(1920, 1080);
	scene->mlxinfo = mlxinfo_init(scene->canvas.width, scene->canvas.height);
	scene->world = NULL;
	scene->lights = NULL;
	parse_file(scene, file_name);
	return (scene);
}
