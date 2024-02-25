#include "../include/minirt.h"

double	ft_atof(const char *s) //s이 올바른 double 형태를 갖춘 경우에 정상 작동하는 atof (문자열 시작과 끝에 공백도 존재하면 안됨)
{
	int		i;
	int		flag;
	double	n;
	double	x;
	int		len;

	i = 0;
	flag = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			flag = -1;
		i++;
	}
	n = 0;
	while (s[i] >= '0' && s[i] <= '9')
		n = n * 10 + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	x = 0;
	len = ft_strlen(s) - 1;
	while (i <= len && (s[i] >= '0' && s[i] <= '9'))
		x = x * 0.1 + (s[len--] - '0') * 0.1;
	return ((n + x) * flag);
}

t_vec3	get_vector(char *s)
{
	char		**elem;
	t_vec3		vector;

	elem = ft_split(s, ',');
	if (count_elem(elem) != 3)
	{
		write(2, "wrong vector info\n", 18);
		exit(1);
	}
	vector.x = atof(elem[0]);
	vector.y = atof(elem[1]);
	vector.z = atof(elem[2]);
	if (!((-1.0 <= vector.x && vector.x <= 1.0)
		&& (-1.0 <= vector.y && vector.y <= 1.0)
		&& (-1.0 <= vector.z && vector.z <= 1.0)))
	{
		write(2, "wrong range vector -1.0~1.0\n", 29);
		exit(1);
	}
	return (vector);
}

t_point3	get_point(char *s)
{
	char		**elem;
	t_point3	point;

	elem = ft_split(s, ',');
	if (count_elem(elem) != 3)
	{
		write(2, "wrong point info\n", 18);
		exit(1);
	}
	point.x = atof(elem[0]);
	point.y = atof(elem[1]);
	point.z = atof(elem[2]);
	return (point);
}

t_color3	get_color(char *s)
{
	char		**elem;
	t_color3	color;

	elem = ft_split(s, ',');
	if (count_elem(elem) != 3)
	{
		write(2, "wrong color info\n", 18);
		exit(1);
	}
	color.x = atof(elem[0]) / 255;
	color.y = atof(elem[1]) / 255;
	color.z = atof(elem[2]) / 255;
	if (!((0.0 <= color.x && color.x <= 1.0)
		&& (0.0 <= color.y && color.y <= 1.0)
		&& (0.0 <= color.z && color.z <= 1.0)))
	{
		write(2, "wrong range color 0~255\n", 25);
		exit(1);
	}
	return (color);
}

int	count_elem(char **elem)
{
	int	cnt;

	cnt = 0;
	while (elem && elem[cnt])
		cnt++;
	return (cnt);
}
