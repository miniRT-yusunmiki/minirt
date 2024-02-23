#include "../../include/structures.h"
#include "../include/minirt.h"

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

t_scene	*scene_init(int ac, char **av)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->canvas = canvas(1920, 1080);
	scene->mlxinfo = mlxinfo_init(scene->canvas.width, scene->canvas.height);
	scene->camera = camera(&scene->canvas, point3(0, 0, 0), vec3(0, 0, 1), 100);
	// scene->world = 파싱하면서 sphere, plane, cylinder 넣기
	// scene->lights = 파싱하면서 lights 넣기
	scene->ambient = (vmult(color3(1, 1, 1), 0.15));
	return (scene);
}
