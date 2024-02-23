#include "../include/minirt.h"

int	main(int argc, char **argv)
{
	t_scene		*scene;

	check_arg(argc, argv);
	scene = set_scene();
	scene->world = NULL;
	scene->light = NULL;
	open_file(scene, argv[1]);
}
