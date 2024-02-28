#include "../../include/minirt.h"

void	parse_line(t_scene *scene, char *s, t_cnt *cnt)
{
	char	**elem;

	elem = ft_split_space(s);
	if (!elem[0])
		return ;
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
	else if (!ft_strncmp(elem[0], "sp", 3))
		oadd(&scene->world, object(SP, set_sphere(elem)));
	else if (!ft_strncmp(elem[0], "pl", 3))
		oadd(&scene->world, object(PL, set_plane(elem)));
	else if (!ft_strncmp(elem[0], "cy", 3))
		oadd(&scene->world, object(CY, set_cylinder(elem)));
	else
	{
		write(2, "non-existent identifier\n", 25);
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
		write(2, "only one ambient, camera, light\n", 33);
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
		write(2, "open fail\n", 11);
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
