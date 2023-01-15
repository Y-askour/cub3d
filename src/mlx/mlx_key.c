/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:40:53 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/15 16:36:23 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	mlx_close(void)
{
	exit(0);
	return (0);
}

int	mlx_key_release(int keycode, t_all *data)
{
	if (keycode == UP)
		data->key.y = 0;
	else if (keycode == DOWN)
		data->key.y = 0;
	else if (keycode == LEFT)
		data->key.x = 0;
	else if (keycode == RIGHT)
		data->key.x = 0;
	else if (keycode == ROTATE_LEFT)
		data->key.pov = 0;
	else if (keycode == ROTATE_RIGHT)
		data->key.pov = 0;
	else if (keycode == ESC)
		exit(0);
	return (0);
}

int	mlx_key(int keycode, t_all *data)
{
	if (keycode == UP)
		data->key.y = 1;
	else if (keycode == DOWN)
		data->key.y = -1;
	else if (keycode == LEFT)
		data->key.x = 1;
	else if (keycode == RIGHT)
		data->key.x = -1;
	else if (keycode == ROTATE_LEFT)
		data->key.pov = 1;
	else if (keycode == ROTATE_RIGHT)
		data->key.pov = -1;
	else if (keycode == ESC)
		exit(0);
	return (0);
}

int	mlx_keypress(t_all *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	if (data->key.pov == 1)
	{
		data->direction_ang -= data->rotation_speed;
		data->direction_ang = normalize_angle(data->direction_ang);
	}
	else if (data->key.pov == -1)
	{
		data->direction_ang += data->rotation_speed;
		data->direction_ang = normalize_angle(data->direction_ang);
	}
	else if (data->key.y == 1)
	{
		if (!check_wall(data, data->y_player + 1 * sin(data->direction_ang), data->x_player + 1 * cos(data->direction_ang)))
		{
			data->x_player = data->x_player + 1 * cos(data->direction_ang);
			data->y_player = data->y_player + 1 * sin(data->direction_ang);
		}
	}
	else if (data->key.y == -1)
	{
		if (!check_wall(data, data->y_player - 1 * sin(data->direction_ang), data->x_player - 1 * cos(data->direction_ang)))
		{
			data->x_player = data->x_player - 1 * cos(data->direction_ang);
			data->y_player = data->y_player - 1 * sin(data->direction_ang);
		}
	}
	else if (data->key.x == 1)
	{
		if (!check_wall(data, data->y_player - 1 * cos(data->direction_ang), data->x_player + 1 * sin(data->direction_ang)))
		{
			data->x_player = data->x_player + 1 * sin(data->direction_ang);
			data->y_player = data->y_player - 1 * cos(data->direction_ang);
		}
	}
	else if (data->key.x == -1)
	{
		if (!check_wall(data, data->y_player + 1 * cos(data->direction_ang), data->x_player - 1 * sin(data->direction_ang)))
		{
			data->x_player = data->x_player - 1 * sin(data->direction_ang);
			data->y_player = data->y_player + 1 * cos(data->direction_ang);
		}
	}
	draw(data);
	return (0);
}
