/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:12:14 by seonmiki          #+#    #+#             */
/*   Updated: 2024/03/11 15:12:15 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	count_elem(char **elem)
{
	int	cnt;

	cnt = 0;
	while (elem && elem[cnt])
		cnt++;
	return (cnt);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (i < count_elem(arr))
		free(arr[i++]);
	free(arr);
}

int	count_comma(char *s)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ',')
			cnt++;
		i++;
	}
	return (cnt);
}
