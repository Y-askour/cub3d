/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:42 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/23 00:39:53 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include_bonus.h"

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

int	check_wall_helper(t_all *data, int x_wall, int y_wall)
{
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall + 1 == data->valid.map_len || x_wall - 1 == -1)
			return (1);
		if (data->valid.maps[y_wall][x_wall - 1] == '1' && \
				data->valid.maps[y_wall + 1][x_wall] == '1')
			return (1);
	}
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall + 1 == data->valid.map_len || x_wall + 1 == \
				data->valid.line_len)
			return (1);
		if (data->valid.maps[y_wall][x_wall + 1] == '1' && \
				data->valid.maps[y_wall + 1][x_wall] == '1')
			return (1);
	}
	return (0);
}

int	check_wall_helper1(t_all *data, int x_wall, int y_wall)
{
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall -1 == -1 || x_wall - 1 == -1)
			return (1);
		if (data->valid.maps[y_wall][x_wall - 1] == '1' \
				&& data->valid.maps[y_wall - 1][x_wall] == '1')
			return (1);
	}
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall - 1 == -1 || x_wall + 1 == data->valid.line_len)
			return (1);
		if (data->valid.maps[y_wall][x_wall + 1] == '1' && \
				data->valid.maps[y_wall - 1][x_wall] == '1')
			return (1);
	}
	return (0);
}

int	check_wall(t_all *data, double y, double x)
{
	int	x_wall;
	int	y_wall;

	x_wall = x / CUB;
	y_wall = y / CUB;
	data->x_p_pos = data->x_player / CUB;
	data->y_p_pos = data->y_player / CUB;
	if (data->valid.maps[(int)y_wall][(int)x_wall] == '1')
		return (1);
	if (check_wall_helper(data, x_wall, y_wall))
		return (1);
	if (check_wall_helper1(data, x_wall, y_wall))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_all	data;

	data.new_pov = 0;
	data.shot_ = 0;
	if (ac != 2)
	{
		printf("Usage : ./cub3d_bonus <filename>\n");
		exit(1);
	}
	else
	{
		if (!parssing(av[1], &data))
		{
			return (1);
		}
		if (check(&data))
			return (1);
		init_mlx(&data);
		draw(&data);
		run(&data);
		return (0);
	}	
	return (0);
}
