/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:38:17 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/22 23:36:05 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

int	middle_char_helper(t_all *data, int i, int j)
{
	char	arr[5];
	int		k;

	k = 0;
	arr[0] = 'W';
	arr[1] = 'S';
	arr[2] = 'E';
	arr[3] = 'N';
	arr[4] = 0;
	while (arr[k])
	{
		if (data->valid.maps[i][j] == arr[k])
		{
			if (data->valid.maps[i][j - 1] == ' ')
				return (1);
			if (data->valid.maps[i][j + 1] == ' ')
				return (1);
			if (data->valid.maps[i - 1][j] == ' ')
				return (1);
			if (data->valid.maps[i + 1][j] == ' ')
				return (1);
		}
		k++;
	}
	return (0);
}

int	middle_char_helper2(t_all *data, int i, int j)
{
	if (data->valid.maps[i][j] == ' ')
	{
		if (data->valid.maps[i][j - 1] != '1' && data->valid.maps[i][j
			- 1] != ' ')
			return (1);
		if (data->valid.maps[i][j + 1] != '1' && data->valid.maps[i][j
			+ 1] != ' ')
			return (1);
		if (data->valid.maps[i - 1][j] != '1' && data->valid.maps[i
			- 1][j] != ' ')
			return (1);
		if (data->valid.maps[i + 1][j] != '1' && data->valid.maps[i
			+ 1][j] != ' ')
			return (1);
	}
	return (0);
}

int	middle_char_helper1(t_all *data, int i, int j)
{
	if (middle_char_helper2(data, i, j))
		return (1);
	if (data->valid.maps[i][j] == '0')
	{
		if (data->valid.maps[i][j - 1] == ' ')
			return (1);
		if (data->valid.maps[i][j + 1] == ' ')
			return (1);
		if (data->valid.maps[i - 1][j] == ' ')
			return (1);
		if (data->valid.maps[i + 1][j] == ' ')
			return (1);
	}
	return (0);
}

void	middle_char_helper3(t_all *data, int *start, int *end, int *i)
{
	*start = 0;
	while (data->valid.maps[*i][*start] && data->valid.maps[*i][*start] == ' ')
		*start += 1;
	*end = data->valid.line_len - 1;
}

void	init_angle(t_all *data)
{
	data->rotation_speed = 5 * (M_PI / 180);
	if (data->valid.player == 'S')
		data->direction_ang = M_PI / 2;
	if (data->valid.player == 'N')
		data->direction_ang = (3 * M_PI) / 2;
	if (data->valid.player == 'W')
		data->direction_ang = M_PI;
	if (data->valid.player == 'E')
		data->direction_ang = 0;
}
