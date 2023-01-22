/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:22:05 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/22 22:25:58 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	horizontal_inter_init(t_all *data, double ang)
{
	data->norm.first_y = floor(data->y_player / CUB) * CUB;
	if (!is_up(ang))
		data->norm.first_y += CUB;
	data->norm.first_x = ((data->norm.first_y - data->y_player) / \
			tan(ang)) + data->x_player;
	data->norm.step_y = CUB;
	if (is_up(ang))
		data->norm.step_y *= -1;
	data->norm.step_x = (CUB / tan(ang));
	if (!is_left(ang) && data->norm.step_x < 0)
		data->norm.step_x *= -1;
	if (is_left(ang) && data->norm.step_x > 0)
		data->norm.step_x *= -1;
}

void	horizontal_inter(t_all *data, double ang)
{
	int		index_x;
	int		index_y;

	horizontal_inter_init(data, ang);
	horizontal_inter_helper(data, ang, &index_x, &index_y);
	while (index_y >= 0 && index_y < data->valid.map_len \
	&& index_x >= 0 && index_x < data->valid.line_len)
	{
		if (data->valid.maps[index_y][index_x] == '1')
		{
			data->hor_x = data->norm.first_x;
			data->hor_y = data->norm.first_y;
			return ;
		}
		data->norm.first_x += data->norm.step_x;
		data->norm.first_y += data->norm.step_y;
		horizontal_inter_helper(data, ang, &index_x, &index_y);
	}
	data->hor_y = INT_MAX;
	data->hor_x = INT_MAX;
	return ;
}

void	vertical_inter_init(t_all *data, double ang)
{
	data->norm.first_x = floor(data->x_player / CUB) * CUB;
	if (!is_left(ang))
		data->norm.first_x += CUB;
	data->norm.first_y = data->y_player + ((data->norm.first_x - \
				data->x_player) * tan(ang));
	data->norm.step_x = CUB;
	if (is_left(ang))
		data->norm.step_x *= -1;
	data->norm.step_y = tan(ang) * CUB;
	if (is_up(ang) && data->norm.step_y > 0)
		data->norm.step_y *= -1;
	if (!is_up(ang) && data->norm.step_y < 0)
		data->norm.step_y *= -1;
}

void	vertical_inter_helper(t_all *data, double ang, int *index_y, \
		int *index_x)
{
	if (is_left(ang))
	{
		*index_x = floor((data->norm.first_x - 1) / CUB);
		*index_y = floor(data->norm.first_y / CUB);
	}
	else
	{
		*index_x = floor(data->norm.first_x / CUB);
		*index_y = floor(data->norm.first_y / CUB);
	}
}

void	vertical_inter(t_all *data, double ang)
{
	int		index_x;
	int		index_y;

	vertical_inter_init(data, ang);
	vertical_inter_helper(data, ang, &index_y, &index_x);
	while (index_y >= 0 && index_y < data->valid.map_len \
	&& index_x >= 0 && index_x < data->valid.line_len)
	{
		if (data->valid.maps[index_y][index_x] == '1')
		{
			data->ver_x = data->norm.first_x;
			data->ver_y = data->norm.first_y;
			return ;
		}
		data->norm.first_x += data->norm.step_x;
		data->norm.first_y += data->norm.step_y;
		vertical_inter_helper(data, ang, &index_y, &index_x);
	}
	data->ver_x = INT_MAX;
	data->ver_y = INT_MAX;
	return ;
}
