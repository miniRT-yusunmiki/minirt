/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:19:48 by seonmiki          #+#    #+#             */
/*   Updated: 2024/02/23 20:40:53 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include "../include/structures.h"

void    my_mlx_pixel_put(t_scene *scene, int x, int y, t_color3	pixel_color)
{
	int			color;
	char		*dst;
	t_mlxinfo	*mlx;

	mlx = scene->mlxinfo;
	color = ((int)(255.999 * pixel_color.x) << 16) + ((int)(255.999 * pixel_color.y) << 8) + ((int)(255.999 * pixel_color.z));
	dst = mlx->img_addr + (y * mlx->len + x * (mlx->pbits / 8));
	*(unsigned int*)dst = color;
}

void	getray_pixelput(int y, int x, t_scene *scene)
{
	double		u;
	double		v;

	u = (double)x / (scene->canvas.width - 1);
	v = (double)y / (scene->canvas.height - 1);
	scene->ray = ray_primary(&scene->camera, u, v);
	my_mlx_pixel_put(scene, x, scene->canvas.height - 1 - y, ray_color(scene));
}

int	main(int ac, char **av)
{
	t_scene		*scene;
	int			y;
	int			x;

	scene = scene_init(ac, av);


	y = 0;
    while (y < scene->canvas.height)
    {
        x = 0;
        while (x < scene->canvas.width)
        {
			getray_pixelput(y, x, scene);
        	x++;
        }
    	y++;
    }
	
	return (0);
}
