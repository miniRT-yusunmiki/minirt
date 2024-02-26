#include "../../include/minirt.h"

void	parse_line(t_scene *scene, char *s)
{
	char	**elem;

	elem = ft_split_space(s);
	if (!elem[0])
		return ;
	if (!ft_strncmp(elem[0], "A", 2))
		scene->ambient = set_ambient(elem);
	else if (!ft_strncmp(elem[0], "C", 2))
	{
		scene->camera = set_camera(elem);
		scene->viewport = set_viewport(scene->canvas, scene->camera);
	}
	else if (!ft_strncmp(elem[0], "L", 2))
		ladd(&scene->lights, set_light(elem));
	else if (!ft_strncmp(elem[0], "sp", 3))
		oadd(&scene->world, object(SP, set_sphere(elem)));
	else if (!ft_strncmp(elem[0], "pl", 3))
		oadd(&scene->world, object(PL, set_plane(elem)));
	else if (!ft_strncmp(elem[0], "cy", 3))
		oadd(&scene->world, object(CY, set_cylinder(elem)));
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
