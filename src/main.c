#include "../include/minirt.h"

int	key_hook(int keycode, t_mlxinfo *mlx_info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
		exit(0);
	}
	return (0);
}

int	rgb_to_int(t_color3 pixel_color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = 255.999 * pixel_color.x;
	g = 255.999 * pixel_color.y;
	b = 255.999 * pixel_color.z;
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_scene *scene, int x, int y, t_color3	pixel_color)
{
	int			color;
	char		*dst;
	t_mlxinfo	*mlx;

	mlx = scene->mlxinfo;
	color = rgb_to_int(pixel_color);
	dst = mlx->img_addr + (y * mlx->len + x * (mlx->pbits / 8));
	*(unsigned int *)dst = color;
}

void	put_ray_pixel(int y, int x, t_scene *scene)
{
	double		u;
	double		v;

	u = (double)x / (scene->canvas.width - 1);
	v = (double)y / (scene->canvas.height - 1);
	scene->ray = ray_primary(scene, u, v);
	my_mlx_pixel_put(scene, x, y, ray_color(scene));
}

int	main(int ac, char **av)
{
	t_scene	*scene;
	int		x;
	int		y;

	check_arg(ac, av);
	scene = set_scene(av[1]);
	// print_info(scene);
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
	mlx_key_hook(scene->mlxinfo->win_ptr, key_hook, scene->mlxinfo);
	mlx_loop(scene->mlxinfo->mlx_ptr);
	return (0);
}
