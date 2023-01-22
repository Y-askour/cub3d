/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:46:35 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/22 20:53:18 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	player_position(t_all *data, int x, int y, int *player)
{
	data->valid.player = data->valid.maps[y][x];
	data->y_player = (y * CUB) + (CUB / 2);
	data->x_player = (x * CUB) + (CUB / 2);
	data->valid.maps[(int)roundf(y)][(int)roundf(x)] = '0';
	*player = *player + 1;
}

int	horizontal_inter(t_all *data, double ang)
{
	int		index_x;
	int		index_y;

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
	if (is_up(ang))
	{
		index_x = floor(data->norm.first_x / CUB);
		index_y = floor((data->norm.first_y - 1) / CUB);
	}
	else
	{
		index_x = floor(data->norm.first_x / CUB);
		index_y = floor((data->norm.first_y) / CUB);
	}
	while (index_y >= 0 && index_y < data->valid.map_len \
	&& index_x >= 0 && index_x < data->valid.line_len)
	{
		if (data->valid.maps[index_y][index_x] == '1')
		{
			data->hor_x = data->norm.first_x;
			data->hor_y = data->norm.first_y;
			return (0);
		}
		data->norm.first_x += data->norm.step_x;
		data->norm.first_y += data->norm.step_y;
		if (is_up(ang))
		{
			index_x = floor(data->norm.first_x / CUB);
			index_y = floor((data->norm.first_y - 1) / CUB);
		}
		else
		{
			index_x = floor(data->norm.first_x / CUB);
			index_y = floor((data->norm.first_y) / CUB);
		}
	}
	data->hor_y = INT_MAX;
	data->hor_x = INT_MAX;
	return (0);
}

int	vertical_inter(t_all *data, double ang)
{
	int		index_x;
	int		index_y;

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
	if (is_left(ang))
	{
		index_x = floor((data->norm.first_x - 1) / CUB);
		index_y = floor(data->norm.first_y / CUB);
	}
	else
	{
		index_x = floor(data->norm.first_x / CUB);
		index_y = floor(data->norm.first_y / CUB);
	}
	while (index_y >= 0 && index_y < data->valid.map_len \
	&& index_x >= 0 && index_x < data->valid.line_len)
	{
		if (data->valid.maps[index_y][index_x] == '1')
		{
			data->ver_x = data->norm.first_x;
			data->ver_y = data->norm.first_y;
			return (0);
		}
		data->norm.first_x += data->norm.step_x;
		data->norm.first_y += data->norm.step_y;
		if (is_left(ang))
		{
			index_x = floor((data->norm.first_x - 1) / CUB);
			index_y = floor(data->norm.first_y / CUB);
		}
		else
		{
			index_x = floor(data->norm.first_x / CUB);
			index_y = floor(data->norm.first_y / CUB);
		}
	}
	data->ver_x = INT_MAX;
	data->ver_y = INT_MAX;
	return (0);
}

int	draw_rays(t_all *data)
{
	int				i;
	int				j;
	double			increment;
	double			x1;
	double			y1;

	data->norm.start_angle = data->direction_ang - (30 * (M_PI / 180));
	data->norm.start_angle = normalize_angle(data->norm.start_angle);
	increment = (60 * (M_PI / 180)) / data->mlx.w_win;
	i = 0;
	while (i < data->mlx.w_win)
	{
		horizontal_inter(data, data->norm.start_angle);
		vertical_inter(data, data->norm.start_angle);
		if (calculate_distance(data, data->ver_y, data->ver_x) > \
		calculate_distance(data, data->hor_y, data->hor_x))
		{
			y1 = data->hor_y;
			x1 = data->hor_x;
			data->x_offset = fmod(x1, CUB);
			if (is_up(data->norm.start_angle))
				data->norm.choice_txt = &data->n_txt;
			else
				data->norm.choice_txt = &data->s_txt;
		}
		else
		{
			y1 = data->ver_y;
			x1 = data->ver_x;
			data->x_offset = fmod(y1, CUB);
			if (is_left(data->norm.start_angle))
				data->norm.choice_txt = &data->e_txt;
			else
				data->norm.choice_txt = &data->w_txt;
		}
		data->norm.cub_distance = calculate_distance(data, y1, x1) / CUB;
		data->norm.cub_distance *= cos(data->direction_ang - \
				data->norm.start_angle);
		data->norm.wall_height = data->mlx.h_win / data->norm.cub_distance;
		data->norm.start = (data->mlx.h_win / 2) - (data->norm.wall_height / 2);
		if (data->norm.start < 0)
			data->norm.start = 0;
		data->norm.end = (data->mlx.h_win / 2) + (data->norm.wall_height / 2);
		if (data->norm.end > data->mlx.h_win || data->norm.end < 0)
			data->norm.end = data->mlx.h_win;
		j = 0;
		while (j < data->norm.start)
		{
			my_mlx_pixel_put(data, i, j, get_ceiling_c(data));
			j++;
		}
		while (j < data->norm.end)
		{
			data->norm.color = get_color(*data->norm.choice_txt, j, data, \
					data->norm.wall_height);
			my_mlx_pixel_put(data, i, j, data->norm.color);
			j++;
		}
		while (j < data->mlx.h_win)
		{
			my_mlx_pixel_put(data, i, j, get_floor_c(data));
			j++;
		}
		data->norm.start_angle += increment;
		i++;
	}
	return (0);
}

int	draw(t_all *data)
{
	draw_rays(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (0);
}
