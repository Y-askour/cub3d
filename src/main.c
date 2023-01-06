/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:42 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/07 00:12:23 by yaskour          ###   ########.fr       */
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
	(void)data;
	int x_wall = floor(x/ CUB);
	int y_wall = floor(y/ CUB);


	if (data->valid.maps[(int)y_wall][(int)x_wall] == '1')
		return (1);

	if (data->direction_ang >= ( (3 * M_PI) / 2) && data->direction_ang <= (2 * M_PI)) // up right
	{
		//if (data->valid.maps[y_wall - 1][x_wall] == '1' && data->valid.maps[y_wall][x_wall + 1] == '1')
		//{
		//	return (1);
		//}
	}
	if (data->direction_ang >= M_PI && data->direction_ang <= ((3 * M_PI) / 2))
	{
	}
	if (data->direction_ang >= 0 && data->direction_ang <= (M_PI / 2))
	{
	}
	if (data->direction_ang >= (M_PI / 2) && data->direction_ang <= M_PI)
	{
		printf("%f\n",data->direction_ang);
	}
	return (0);
}

void	normalize_angle(t_all *data)
{
	data->direction_ang = fmod(data->direction_ang, 2 * M_PI);
	if (data->direction_ang < 0)
		data->direction_ang += 2 * M_PI;
}

int	younes(int keycode, t_all *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	if (keycode == ESC)
		exit(0);
	else if (keycode == ROTATE_LEFT)
	{
		//data->rotation_speed = fmod(data->rotation_speed + 23, 24);
		data->direction_ang += data->rotation_speed;
		normalize_angle(data);
	}
	else if (keycode == ROTATE_RIGHT)
	{
		//data->rotation_speed = fmod(data->rotation_speed + 1, 24);
		data->direction_ang -= data->rotation_speed;
		normalize_angle(data);
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
