/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:05:33 by seonmiki          #+#    #+#             */
/*   Updated: 2024/03/11 15:05:34 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	shoot_ray(t_scene *scene, int dummy)
{
	int	y;
	int	x;

	y = 0;
	while (y < scene->canvas.height)
	{
		x = 0;
		while (x < scene->canvas.width)
		{
			put_ray_pixel(y, x, scene, dummy);
			if (dummy == TRUE)
				x += 50;
			else
				x++;
		}
		if (dummy == TRUE)
			y += 50;
		else
			y++;
	}
	mlx_put_image_to_window(scene->mlxinfo->mlx_ptr, scene->mlxinfo->win_ptr,
		scene->mlxinfo->img_ptr, 0, 0);
}
