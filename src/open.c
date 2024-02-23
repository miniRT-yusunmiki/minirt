#include "../include/minirt.h"

void	check_elem(t_scene *scene, char *s)
{
	char		**elem;

	elem = ft_split_space(s);
	if (!elem)
		return ;
	if (!ft_strncmp(elem[0], "A", 2) || !ft_strncmp(elem[0], "C", 2) || !ft_strncmp(elem[0], "L", 2))
	{
		if (!ft_strncmp(elem[0], "A", 2))
			scene->ambient = parse_ambient_info(elem);
		else if (!ft_strncmp(elem[0], "C", 2))
			scene->camera = parse_camera_info(elem);
		else if (!ft_strncmp(elem[0], "L", 2))
			ladd(&scene->light, parse_light_info(elem)); // 빛이 여러개인 경우 처리 필요함
	}
	else if (!ft_strncmp(elem[0], "sp", 3) || !ft_strncmp(elem[0], "pl", 3) || !ft_strncmp(elem[0], "cy", 3))
	{
		if (!ft_strncmp(elem[0], "sp", 3))
			oadd(&scene->world, object(SP, parse_sphere_info(elem)));
		else if (!ft_strncmp(elem[0], "pl", 3))
			oadd(&scene->world, object(PL, parse_plane_info(elem)));
		else if (!ft_strncmp(elem[0], "cy", 3))
			oadd(&scene->world, object(CY, parse_cylinder_info(elem)));
	}
	else // 부적절한 식별자, 적절한 경우에는 식별자에 따라서 parse 함수 호출
	{
		write(2, "non-existent identifier\n", 24);
		exit(1);
	}
}

void	open_file(t_scene *scene, char *file_name)
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
			break;
		char *elem = ft_strtrim(line, "\n");
		check_elem(scene, elem);
	}
	close(fd);
}
