/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusung <yusung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:48:53 by yusung            #+#    #+#             */
/*   Updated: 2024/03/11 15:48:53 by yusung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	all_free(char **result, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(result[i++]);
	free(result);
}

static int	check_cnt(const char *str)
{
	int	cnt;
	int	flag;
	int	i;

	cnt = 0;
	flag = 0;
	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		while (str[i] && !ft_isspace(str[i]))
		{
			flag++;
			i++;
		}
		if (flag != 0)
		{
			cnt++;
			flag = 0;
		}
	}
	return (cnt);
}

static char	**allocate_len(char **result, const char *s, int cnt)
{
	int	flag;
	int	i;

	i = -1;
	while (++i < cnt)
	{
		flag = 0;
		while (ft_isspace(*s))
			s++;
		while (s[flag] && !ft_isspace(s[flag]))
			flag++;
		if (flag != 0)
		{
			result[i] = (char *)malloc(sizeof(char) * (flag + 1));
			if (result[i] == 0)
			{
				all_free(result, i);
				return (0);
			}
			ft_strncpy(result[i], s, flag);
			s += flag;
		}
	}
	result[i] = 0;
	return (result);
}

char	**ft_split_space(const char *s)
{
	char	**result;
	int		cnt;

	cnt = check_cnt(s);
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (result == 0)
		return (0);
	result = allocate_len(result, s, cnt);
	return (result);
}
