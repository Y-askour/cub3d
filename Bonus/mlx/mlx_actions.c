/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:39:45 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/22 23:26:43 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

void	move_up(t_all *data)
{
	if (!check_wall(data, data->y_player + 1 * sin(data->direction_ang), \
	data->x_player + 1 * cos(data->direction_ang)))
	{
	data->x_player = data->x_player + 1 * cos(data->direction_ang);
	data->y_player = data->y_player + 1 * sin(data->direction_ang);
	}
	else
	{
		if (!check_wall(data, data->y_player + 1 * sin(data->direction_ang), \
		data->x_player))
		{
			data->y_player = data->y_player + 1 * sin(data->direction_ang);
		}
		if (!check_wall(data, data->y_player, \
		data->x_player + 1 * cos(data->direction_ang)))
		{
			data->x_player = data->x_player + 1 * cos(data->direction_ang);
		}
	}
}

void	move_down(t_all *data)
{
	if (!check_wall(data, data->y_player - 1 * sin(data->direction_ang), \
	data->x_player - 1 * cos(data->direction_ang)))
	{
		data->x_player = data->x_player - 1 * cos(data->direction_ang);
		data->y_player = data->y_player - 1 * sin(data->direction_ang);
	}
	else
	{
		if (!check_wall(data, data->y_player - 1 * sin(data->direction_ang), \
		data->x_player))
		{
			data->y_player = data->y_player - 1 * sin(data->direction_ang);
		}
		if (!check_wall(data, data->y_player, \
		data->x_player - 1 * cos(data->direction_ang)))
		{
			data->x_player = data->x_player - 1 * cos(data->direction_ang);
		}
	}
}

void	move_left(t_all *data)
{
	if (!check_wall(data, data->y_player - 1 * cos(data->direction_ang), \
	data->x_player + 1 * sin(data->direction_ang)))
	{
		data->x_player = data->x_player + 1 * sin(data->direction_ang);
		data->y_player = data->y_player - 1 * cos(data->direction_ang);
	}
	else
	{
		if (!check_wall(data, data->y_player - 1 * cos(data->direction_ang), \
		data->x_player))
		{
			data->y_player = data->y_player - 1 * cos(data->direction_ang);
		}
		if (!check_wall(data, data->y_player, \
		data->x_player + 1 * sin(data->direction_ang)))
		{
			data->x_player = data->x_player + 1 * sin(data->direction_ang);
		}
	}
}

void	move_right(t_all *data)
{
	if (!check_wall(data, data->y_player + 1 * cos(data->direction_ang), \
	data->x_player - 1 * sin(data->direction_ang)))
	{
		data->x_player = data->x_player - 1 * sin(data->direction_ang);
		data->y_player = data->y_player + 1 * cos(data->direction_ang);
	}
	else
	{
		if (!check_wall(data, data->y_player + 1 * cos(data->direction_ang), \
		data->x_player))
		{
			data->y_player = data->y_player + 1 * cos(data->direction_ang);
		}
		if (!check_wall(data, data->y_player, \
		data->x_player - 1 * sin(data->direction_ang)))
		{
			data->x_player = data->x_player - 1 * sin(data->direction_ang);
		}
	}
}

void	rotate_left_and_right(t_all *data, int direction)
{
	if (direction == 1)
	{
		data->direction_ang -= data->rotation_speed;
		data->direction_ang = normalize_angle(data->direction_ang);
	}
	else if (direction == 2)
	{
		data->direction_ang += data->rotation_speed;
		data->direction_ang = normalize_angle(data->direction_ang);
	}
}
