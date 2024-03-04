#include "../include/minirt.h"

void	shoot_ray(t_scene *scene)
{
	int	y;
	int	x;

	y = 0;
	while (y < scene->canvas.height)
	{
		x = 0;
		while (x < scene->canvas.width)
		{
			put_ray_pixel(y, x, scene);
			// printf("%lf %f %lf\n", scene->ray.dir.x, scene->ray.dir.y, scene->ray.dir.z);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(scene->mlxinfo->mlx_ptr, scene->mlxinfo->win_ptr,
		scene->mlxinfo->img_ptr, 0, 0);
}

int	main(int ac, char **av)
{
	t_scene	*scene;

	check_arg(ac, av);
	scene = set_scene(av[1]);
	// print_info(scene);
	shoot_ray(scene);
	mlx_key_hook(scene->mlxinfo->win_ptr, key_hook, scene->mlxinfo);
	mlx_loop(scene->mlxinfo->mlx_ptr);
	return (0);
}
