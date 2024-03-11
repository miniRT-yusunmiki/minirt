#include "../../include/minirt.h"

int	sign_check(const char *s, int *i)
{
	int	sign;
	int	idx;
	int	cnt_dot;

	sign = 1;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign = -1;
		*i += 1;
	}
	cnt_dot = 0;
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

double	check_double_range(double n, double x)
{
	double	result;

	result = n + x;
	if (result == 0.0 && fabs(result - n) >= 1.0)
	{
		write(2, "Error\nwrong double format\n", 27);
		exit(1);
	}
	return (result);
}

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
		write(2, "Error\nwrong double format\n", 27);
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
	return (check_double_range(n, x) * sign);
}

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
