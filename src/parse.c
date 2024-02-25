#include "../include/minirt.h"

void	parse_line(t_scene *scene, char *s)
{
	char	**elem;

	elem = ft_split_space(s);
	if (!elem[0])
		return ;
	if (!ft_strncmp(elem[0], "A", 2))
		scene->ambient = parse_ambient_info(elem);
	else if (!ft_strncmp(elem[0], "C", 2))
	{
		scene->camera = parse_camera_info(elem);
		scene->viewport = set_viewport(scene->canvas, scene->camera);
	}
	else if (!ft_strncmp(elem[0], "L", 2))
		ladd(&scene->lights, parse_light_info(elem));
	else if (!ft_strncmp(elem[0], "sp", 3))
		oadd(&scene->world, object(SP, parse_sphere_info(elem)));
	else if (!ft_strncmp(elem[0], "pl", 3))
		oadd(&scene->world, object(PL, parse_plane_info(elem)));
	else if (!ft_strncmp(elem[0], "cy", 3))
		oadd(&scene->world, object(CY, parse_cylinder_info(elem)));
	else
	{
		write(2, "non-existent identifier\n", 24);
		exit(1);
	}
	free_arr(elem);
}

void	parse_file(t_scene *scene, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		write(2, "open fail\n", 10);
		exit(1);
	}
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		parse_line(scene, line);
		free(line);
	}
	close(fd);
}
