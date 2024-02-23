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
	vector.x = atof(elem[0]);
	vector.y = atof(elem[1]);
	vector.z = atof(elem[2]);
	return (vector);
}

t_point3	get_point(char *s)
{
	char		**elem;
	t_point3	point;

	elem = ft_split(s, ',');
	point.x = atof(elem[0]);
	point.y = atof(elem[1]);
	point.z = atof(elem[2]);
	return (point);
}

t_color3	get_color(char *s)
{
	char		**elem;
	t_color3	point;

	elem = ft_split(s, ',');
	point.x = atof(elem[0]) / 255;
	point.y = atof(elem[1]) / 255;
	point.z = atof(elem[2]) / 255;
	return (point);
}

int	count_elem(char **elem)
{
	int	cnt;

	cnt = 0;
	while (elem && elem[cnt])
		cnt++;
	return (cnt);
}
