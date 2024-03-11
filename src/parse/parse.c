/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusung <yusung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:46:54 by yusung            #+#    #+#             */
/*   Updated: 2024/03/11 15:46:55 by yusung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	set_info(t_scene *scene, char **elem, t_cnt *cnt)
{
	if (!ft_strncmp(elem[0], "A", 2))
	{
		scene->ambient = set_ambient(elem);
		cnt->a += 1;
	}
	else if (!ft_strncmp(elem[0], "C", 2))
	{
		scene->camera = set_camera(elem);
		scene->viewport = set_viewport(scene->canvas, scene->camera);
		cnt->c += 1;
	}
	else if (!ft_strncmp(elem[0], "L", 2))
	{
		ladd(&scene->lights, set_light(elem));
		cnt->l += 1;
	}
}

void	parse_line(t_scene *scene, char *s, t_cnt *cnt)
{
	char	**elem;

	elem = ft_split_space(s);
	if (!elem[0])
		return ;
	if (!ft_strncmp(elem[0], "A", 2) || !ft_strncmp(elem[0], "C", 2)
		|| !ft_strncmp(elem[0], "L", 2))
		set_info(scene, elem, cnt);
	else if (!ft_strncmp(elem[0], "sp", 3))
		oadd(&scene->world, object(SP, set_sphere(elem)));
	else if (!ft_strncmp(elem[0], "pl", 3))
		oadd(&scene->world, object(PL, set_plane(elem)));
	else if (!ft_strncmp(elem[0], "cy", 3))
		oadd(&scene->world, object(CY, set_cylinder(elem)));
	else
	{
		write(2, "Error\nnon-existent identifier\n", 31);
		exit(1);
	}
	free_arr(elem);
}

void	init_cnt(t_cnt *cnt)
{
	cnt->a = 0;
	cnt->c = 0;
	cnt->l = 0;
}

void	check_id_cnt(t_cnt cnt)
{
	if (cnt.a != 1 || cnt.c != 1 || cnt.l != 1)
	{
		write(2, "Error\nonly one ambient, camera, light\n", 39);
		exit(1);
	}
}

void	parse_file(t_scene *scene, char *file_name)
{
	int		fd;
	char	*line;
	t_cnt	cnt;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nopen failed\n", 19);
		exit(1);
	}
	init_cnt(&cnt);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		parse_line(scene, line, &cnt);
		free(line);
	}
	close(fd);
	check_id_cnt(cnt);
}
