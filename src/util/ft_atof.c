/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusung <yusung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:32:24 by yusung            #+#    #+#             */
/*   Updated: 2024/03/11 15:32:40 by yusung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
