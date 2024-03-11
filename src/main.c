#include "../include/minirt.h"

void	leak(void)
{
	system("leaks miniRT");
}

int	main(int ac, char **av)
{
	atexit(leak);
	t_scene	*scene;

	check_arg(ac, av);
	scene = set_scene(av[1]);
	// print_info(scene);
	shoot_ray(scene, FALSE);
	mlx_key_hook(scene->mlxinfo->win_ptr, key_hook, scene);
	mlx_hook(scene->mlxinfo->win_ptr, 17, 0, exit_hook, 0);
	mlx_loop(scene->mlxinfo->mlx_ptr);
	return (0);
}
