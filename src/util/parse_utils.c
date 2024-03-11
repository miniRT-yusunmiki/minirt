/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusung <yusung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:10:10 by seonmiki          #+#    #+#             */
/*   Updated: 2024/03/11 15:32:17 by yusung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec3	get_vector(char *s)
{
	char		**elem;
	t_vec3		vector;

	elem = ft_split(s, ',');
	if (count_comma(s) != 2 || count_elem(elem) != 3)
	{
		write(2, "Error\nwrong vector info\n", 25);
		exit(1);
	}
	vector.x = ft_atof(elem[0]);
	vector.y = ft_atof(elem[1]);
	vector.z = ft_atof(elem[2]);
	if (!((-1.0 <= vector.x && vector.x <= 1.0)
			&& (-1.0 <= vector.y && vector.y <= 1.0)
			&& (-1.0 <= vector.z && vector.z <= 1.0)))
	{
		write(2, "Error\nwrong range vector -1.0~1.0\n", 35);
		exit(1);
	}
	free_arr(elem);
	return (vector);
}

t_point3	get_point(char *s)
{
	char		**elem;
	t_point3	point;

	if (count_comma(s) != 2)
	{
		write(2, "Error\nwrong point info\n", 24);
		exit(1);
	}
	elem = ft_split(s, ',');
	if (count_elem(elem) != 3)
	{
		write(2, "Error\nwrong point info\n", 24);
		exit(1);
	}
	point.x = ft_atof(elem[0]);
	point.y = ft_atof(elem[1]);
	point.z = ft_atof(elem[2]);
	free_arr(elem);
	return (point);
}

t_color3	get_color(char *s)
{
	char		**elem;
	t_color3	color;

	elem = ft_split(s, ',');
	if (count_comma(s) != 2 || count_elem(elem) != 3)
	{
		write(2, "Error\nwrong color info\n", 24);
		exit(1);
	}
	color.x = ft_atof(elem[0]) / 255;
	color.y = ft_atof(elem[1]) / 255;
	color.z = ft_atof(elem[2]) / 255;
	if (!((0.0 <= color.x && color.x <= 1.0)
			&& (0.0 <= color.y && color.y <= 1.0)
			&& (0.0 <= color.z && color.z <= 1.0)))
	{
		write(2, "Error\nwrong range color 0~255\n", 31);
		exit(1);
	}
	free_arr(elem);
	return (color);
}
