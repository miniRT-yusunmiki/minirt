#include "../include/minirt.h"

void	all_free2(char **result, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(result[i++]);
	free(result);
}

int	check_cnt2(const char *str)
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

void	ft_strncpy2(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = 0;
}

char	**allocate_len2(char **result, const char *s, int cnt)
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
				all_free2(result, i);
				return (0);
			}
			ft_strncpy2(result[i], s, flag);
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

	cnt = check_cnt2(s);
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (result == 0)
		return (0);
	result = allocate_len2(result, s, cnt);
	return (result);
}
