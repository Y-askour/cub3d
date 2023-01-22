/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:34:24 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/22 23:36:23 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

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
	if (check_player(data, 0, 0, 0))
		return (1);
	return (0);
}

int	check_player(t_all *data, int i, int j, int player)
{
	while (data->valid.maps[i])
	{
		j = 0;
		while (data->valid.maps[i][j])
		{
			if (data->valid.maps[i][j] == 'W')
				player_position(data, j, i, &player);
			if (data->valid.maps[i][j] == 'E')
				player_position(data, j, i, &player);
			if (data->valid.maps[i][j] == 'S')
				player_position(data, j, i, &player);
			if (data->valid.maps[i][j] == 'N')
				player_position(data, j, i, &player);
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
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
		middle_char_helper3(data, &start, &end, &i);
		while (end > 0 && data->valid.maps[i][end] == ' ')
			end -= 1;
		j = start;
		while (j < end)
		{
			if (middle_char_helper1(data, i, j))
				return (1);
			if (middle_char_helper(data, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
