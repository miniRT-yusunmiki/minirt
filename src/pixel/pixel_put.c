#include "../../include/minirt.h"

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

void	put_ray_pixel(int y, int x, t_scene *scene, int dummy)
{
	double		u;
	double		v;
	int			yy;
	int			xx;
	t_color3	pixel_color;

	u = (double)x / (double)(scene->canvas.width - 1) * scene->viewport.width;
	v = (double)y / (double)(scene->canvas.height - 1) * scene->viewport.height;
	scene->ray = ray_primary(scene, u, v);
	pixel_color = ray_color(scene);
	if (dummy == FALSE)
		my_mlx_pixel_put(scene, x, y, pixel_color);
	else
	{
		yy = 0;
		while (yy < 50 && y + yy++ < scene->canvas.height - 1)
		{
			xx = 0;
			while (xx < 50 && x + xx++ < scene->canvas.width - 1)
				my_mlx_pixel_put(scene, x + xx, y + yy, pixel_color);
		}
	}
}
