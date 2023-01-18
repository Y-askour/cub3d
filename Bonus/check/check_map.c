/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:24:25 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/18 19:09:37 by yaskour          ###   ########.fr       */
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

int	middle_char(t_all *data)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 1;
	while (i < data->valid.map_len - 1)
	{
		start = 0;
		while (data->valid.maps[i][start] && data->valid.maps[i][start] == ' ')
			start++;
		end = data->valid.line_len - 1;
		while (end > 0 && data->valid.maps[i][end] == ' ')
			end--;
		j = start;
		while (j < end)
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
			if (middle_char_helper(data, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_player(t_all *data)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (data->valid.maps[i])
	{
		j = 0;
		while (data->valid.maps[i][j])
		{
			if (data->valid.maps[i][j] == 'W')
			{
				player_position(data, j, i);
				player++;
			}
			if (data->valid.maps[i][j] == 'E')
			{
				player_position(data, j, i);
				player++;
			}
			if (data->valid.maps[i][j] == 'S')
			{
				player_position(data, j, i);
				player++;
			}
			if (data->valid.maps[i][j] == 'N')
			{
				player_position(data, j, i);
				player++;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}

int	check_valid_map(t_all *data)
{
	if (search(data->valid.maps[0], " 1"))
		return (1);
	if (search(data->valid.maps[data->valid.map_len - 1], " 1"))
		return (1);
	if (first_and_last_char(data->valid.maps, data->valid.map_len,
			data->valid.line_len))
		return (1);
	if (middle_char(data))
		return (1);
	if (check_player(data))
		return (1);
	return (0);
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

int	check_map(t_all *data)
{
	init_map(data);
	add_space(data);
	if (check_characters(data))
	{
		free_maps(data);
		printf("invalid map characters\n");
		return (1);
	}
	if (check_valid_map(data))
	{
		free_maps(data);
		printf("invalid map \n");
		return (1);
	}
	init_angle(data);
	return (0);
}
