#include "../../include/minirt.h"

int	sign_check(const char *s, int *i)
{
	int	sign;
	int	idx;

	sign = 1;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign = -1;
		*i += 1;
	}
	int cnt_dot = 0;
	idx = *i;
	while (s[idx])
	{
		if (!ft_isdigit(s[idx]) && s[idx] != '.')
			return (WRONG_INFO);
		if (s[idx] == '.')
			cnt_dot++;
		idx++;
	}
	if (cnt_dot > 1)
		return (WRONG_INFO);
	return (sign);
}

//s 이 올바른 double 형태를 갖춘 경우에 정상 작동하는 ft_atof (문자열 시작과 끝에 공백도 존재하면 안됨)
double	ft_atof(const char *s) 
{
	int		i;
	int		sign;
	double	n;
	double	x;
	int		len;

	i = 0;
	sign = sign_check(s, &i);
	if (sign == WRONG_INFO)
	{
		write(2, "wrong double format\n", 21);
		exit(1);
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
	x = n + x;
	if (fabs(x - n) >= 1.0)
	{
		write(2, "wrong double format\n", 21);
		exit(1);
	}
	printf("%f\n", x * sign);
	return (x * sign);
}

t_vec3	get_vector(char *s)
{
	char		**elem;
	t_vec3		vector;

	elem = ft_split(s, ',');
	if (count_elem(elem) != 3)
	{
		write(2, "wrong vector info\n", 19);
		exit(1);
	}
	vector.x = ft_atof(elem[0]);
	vector.y = ft_atof(elem[1]);
	vector.z = ft_atof(elem[2]);
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
	point.x = ft_atof(elem[0]);
	point.y = ft_atof(elem[1]);
	point.z = ft_atof(elem[2]);
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
	color.x = ft_atof(elem[0]) / 255;
	color.y = ft_atof(elem[1]) / 255;
	color.z = ft_atof(elem[2]) / 255;
	if (!((0.0 <= color.x && color.x <= 1.0)
			&& (0.0 <= color.y && color.y <= 1.0)
			&& (0.0 <= color.z && color.z <= 1.0)))
	{
		write(2, "wrong range color 0~255\n", 25);
		exit(1);
	}
	return (color);
}
