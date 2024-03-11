/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusung <yusung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:46:59 by yusung            #+#    #+#             */
/*   Updated: 2024/03/11 15:48:11 by yusung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_sphere	*set_sphere(char **elem)
{
	t_sphere	*sphere;
	double		diameter;

	if (count_elem(elem) != 4)
	{
		write(2, "Error\nwrong sphere info\n", 25);
		exit(1);
	}
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->center = get_point(elem[1]);
	diameter = ft_atof(elem[2]);
	sphere->radius = diameter * 0.5;
	sphere->radius2 = pow(sphere->radius, 2);
	sphere->color = get_color(elem[3]);
	return (sphere);
}

t_plane	*set_plane(char **elem)
{
	t_plane	*plane;

	if (count_elem(elem) != 4)
	{
		write(2, "Error\nwrong plane info\n", 24);
		exit(1);
	}
	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->point = get_point(elem[1]);
	plane->normal = vunit(get_vector(elem[2]));
	plane->color = get_color(elem[3]);
	return (plane);
}

t_cylinder	*set_cylinder(char **elem)
{
	t_cylinder	*cy;

	if (count_elem(elem) != 6)
	{
		write(2, "Error\nwrong cylinder info\n", 27);
		exit(1);
	}
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	cy->center = get_point(elem[1]);
	cy->normal = vunit(get_vector(elem[2]));
	cy->radius = ft_atof(elem[3]) * 0.5;
	cy->height = ft_atof(elem[4]);
	cy->color = get_color(elem[5]);
	cy->top_center = vplus(cy->center, vmults(cy->normal, cy->height / 2));
	cy->bottom_center = \
		vplus(cy->center, vmults(cy->normal, (cy->height / 2) * -1));
	return (cy);
}
