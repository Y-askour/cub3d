/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:42 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/10 23:42:23 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "../include/include.h"

int	check(t_all *data)
{
	if (check_colors(data))
		return (1);
	if (check_textures(data))
	{
		free_map(data);
		free_textures(data);
		return (1);
	}
	if (check_map(data))
	{
		free_textures(data);
		return (1);
	}
	return (0);
}

int	check_wall(t_all *data, double y, double x)
{
	int	x_wall;
	int	y_wall;
	int	x_p_pos;
	int	y_p_pos;

	x_wall = x / CUB;
	y_wall = y / CUB;
	x_p_pos = data->x_player / CUB;
	y_p_pos = data->y_player / CUB;
	if (data->valid.maps[(int)y_wall][(int)x_wall] == '1')
		return (1);
	if (x_wall != x_p_pos && y_wall != y_p_pos)
	{
		if (y_wall + 1 == data->valid.map_len || x_wall - 1 == -1)
			return (1);
		if (data->valid.maps[y_wall][x_wall - 1] == '1' && data->valid.maps[y_wall + 1][x_wall] == '1')
			return (1);
	}
	if (x_wall != x_p_pos && y_wall != y_p_pos)
	{
		if (y_wall + 1 == data->valid.map_len || x_wall + 1 == data->valid.line_len)
			return (1);
		if (data->valid.maps[y_wall][x_wall + 1] == '1' && data->valid.maps[y_wall + 1][x_wall] == '1')
			return (1);
	}
	if (x_wall != x_p_pos && y_wall != y_p_pos)
	{
		if (y_wall -1 == -1 || x_wall - 1 == -1)
			return (1);
		if (data->valid.maps[y_wall][x_wall - 1] == '1' && data->valid.maps[y_wall - 1][x_wall] == '1')
			return (1);
	}
	if (x_wall != x_p_pos && y_wall != y_p_pos)
	{
		if (y_wall - 1 == -1 || x_wall + 1 == data->valid.line_len)
			return (1);
		if (data->valid.maps[y_wall][x_wall + 1] == '1' && data->valid.maps[y_wall - 1][x_wall] == '1')
			return (1);
	}
	return (0);
}

double	normalize_angle(double ang)
{
	ang = fmod(ang, 2 * M_PI);
	if (ang < 0)
		ang += 2 * M_PI;
	return (ang);
}

int	younes(int keycode, t_all *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	if (keycode == ESC)
		exit(0);
	else if (keycode == ROTATE_LEFT)
	{
		data->direction_ang += data->rotation_speed;
		data->direction_ang = normalize_angle(data->direction_ang);
	}
	else if (keycode == ROTATE_RIGHT)
	{
		data->direction_ang -= data->rotation_speed;
		data->direction_ang = normalize_angle(data->direction_ang);
	}
	else if (keycode == UP)
	{
		if (!check_wall(data, data->y_player + 5 * sin(data->direction_ang), data->x_player + 5 * cos(data->direction_ang)))
		{
			data->x_player = data->x_player + 5 * cos(data->direction_ang);
			data->y_player = data->y_player + 5 * sin(data->direction_ang);
		}
	}
	else if (keycode == DOWN)
	{
		if (!check_wall(data, data->y_player - 5 * sin(data->direction_ang), data->x_player - 5 * cos(data->direction_ang)))
		{
			data->x_player = data->x_player - 5 * cos(data->direction_ang);
			data->y_player = data->y_player - 5 * sin(data->direction_ang);
		}
	}
	else if (keycode == LEFT)
	{
		if (!check_wall(data, data->y_player - 5 * cos(data->direction_ang), data->x_player + 5 * sin(data->direction_ang)))
		{
			data->x_player = data->x_player + 5 * sin(data->direction_ang);
			data->y_player = data->y_player - 5 * cos(data->direction_ang);
		}
	}
	else if (keycode == RIGHT)
	{
		if (!check_wall(data, data->y_player + 5 * cos(data->direction_ang), data->x_player - 5 * sin(data->direction_ang)))
		{
			data->x_player = data->x_player - 5 * sin(data->direction_ang);
			data->y_player = data->y_player + 5 * cos(data->direction_ang);
		}
	}
	draw(data);
	return (0);
}

int	test(int keycode, t_all *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	if (keycode == 124)
		printf("keycode\n");
	return (0);
}

//i = 0;
//while (data.valid.maps[i])
//	free(data.valid.maps[i++]);
//free(data.valid.maps);
//free(data.valid.we);
//free(data.valid.so);
//free(data.valid.ea);
//free(data.valid.no);
		//mlx_hook(data.mlx.win, 3, 1L<<1, test, NULL);
int	main(int ac, char **av)
{
	t_all	data;
	int		i;

	i = 0;
	if (ac == 2)
	{
		if (!parssing(av[1], &data))
		{
			return (1);
		}
		if (check(&data))
			return (1);
		init_mlx(&data);
		draw(&data);
		mlx_hook(data.mlx.win, 2, 1L << 0, younes, &data);
		mlx_loop(data.mlx.mlx);
		return (0);
	}
	else
		printf("number of args is not valid\n");
	return (0);
}
