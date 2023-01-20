/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:40:53 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/20 02:27:12 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

int	mouse_move(int x, int y, t_all *data)
{
	static int	old_x;

	if (y < 0 || y > data->mlx.h_win)
		return (0);
	if (x <= data->mlx.w_win && x >= 0 && x < old_x)
	{
		data->direction_ang -= data->rotation_speed;
		data->direction_ang = normalize_angle(data->direction_ang);
	}
	if (x >= 0 && x <= data->mlx.w_win && x > old_x)
	{
		data->direction_ang += data->rotation_speed;
		data->direction_ang = normalize_angle(data->direction_ang);
	}
	old_x = x;
	if (!(x >= 0 && x <= data->mlx.w_win))
		old_x = data->mlx.w_win / 2;
	return (0);
}

int	mlx_close(t_all *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	exit(0);
	return (1);
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
	if (keycode == ROTATE_UP && data->new_pov < 50)
		data->new_pov += 5;
	if (keycode == ROTATE_DOWN && data->new_pov > -50)
		data->new_pov -= 5;
	return (0);
}

int	mlx_keypress(t_all *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	if (data->key.pov == 1)
		rotate_left_and_right(data, 1);
	else if (data->key.pov == -1)
		rotate_left_and_right(data, 2);
	else if (data->key.y == 1)
		move_up(data);
	else if (data->key.y == -1)
		move_down(data);
	else if (data->key.x == 1)
		move_left(data);
	else if (data->key.x == -1)
		move_right(data);
	draw(data);
	return (0);
}
