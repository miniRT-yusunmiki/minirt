#include "../include/minirt.h"

int	main(int argc, char **argv)
{
	t_scene		*scene;

	check_arg(argc, argv);
	scene = set_scene(argv[1]);
	printf("%lf %lf %lf\n", scene->ambient.x, scene->ambient.y, scene->ambient.z);
}
