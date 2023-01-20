/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:46:35 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/20 20:24:28 by yaskour          ###   ########.fr       */
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
	double	first_x;
	double	first_y;
	double	step_y;
	double	step_x;
	int		index_x;
	int		index_y;

	first_y = floor(data->y_player / CUB) * CUB;
	if (!is_up(ang))
		first_y += CUB;
	first_x = ((first_y - data->y_player) / tan(ang)) + data->x_player;
	step_y = CUB;
	if (is_up(ang))
		step_y *= -1;
	step_x = (CUB / tan(ang));
	if (!is_left(ang) && step_x < 0)
		step_x *= -1;
	if (is_left(ang) && step_x > 0)
		step_x *= -1;
	if (is_up(ang))
	{
		index_x = floor(first_x / CUB);
		index_y = floor((first_y - 1) / CUB);
	}
	else
	{
		index_x = floor(first_x / CUB);
		index_y = floor((first_y) / CUB);
	}
	while (index_y >= 0 && index_y < data->valid.map_len \
	&& index_x >= 0 && index_x < data->valid.line_len)
	{
		if (data->valid.maps[index_y][index_x] == '1')
		{
			data->hor_x = first_x;
			data->hor_y = first_y;
			return (0);
		}
		first_x += step_x;
		first_y += step_y;
		if (is_up(ang))
		{
			index_x = floor(first_x / CUB);
			index_y = floor((first_y - 1) / CUB);
		}
		else
		{
			index_x = floor(first_x / CUB);
			index_y = floor((first_y) / CUB);
		}
	}
	data->hor_y = INT_MAX;
	data->hor_x = INT_MAX;
	return (0);
}

int	vertical_inter(t_all *data, double ang)
{
	double	first_x;
	double	first_y;
	double	step_x;
	double	step_y;
	int		index_x;
	int		index_y;

	first_x = floor(data->x_player / CUB) * CUB;
	if (!is_left(ang))
		first_x += CUB;
	first_y = data->y_player + ((first_x - data->x_player) * tan(ang));
	step_x = CUB;
	if (is_left(ang))
		step_x *= -1;
	step_y = tan(ang) * CUB;
	if (is_up(ang) && step_y > 0)
		step_y *= -1;
	if (!is_up(ang) && step_y < 0)
		step_y *= -1;
	if (is_left(ang))
	{
		index_x = floor((first_x - 1) / CUB);
		index_y = floor(first_y / CUB);
	}
	else
	{
		index_x = floor(first_x / CUB);
		index_y = floor(first_y / CUB);
	}
	while (index_y >= 0 && index_y < data->valid.map_len \
	&& index_x >= 0 && index_x < data->valid.line_len)
	{
		if (data->valid.maps[index_y][index_x] == '1')
		{
			data->ver_x = first_x;
			data->ver_y = first_y;
			return (0);
		}
		first_x += step_x;
		first_y += step_y;
		if (is_left(ang))
		{
			index_x = floor((first_x - 1) / CUB);
			index_y = floor(first_y / CUB);
		}
		else
		{
			index_x = floor(first_x / CUB);
			index_y = floor(first_y / CUB);
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
	double			start_angle;
	double			increment;
	double			x1;
	double			y1;
	double			cub_distance;
	double			wall_height;
	int				start;
	int				end;
	unsigned int	color;
	t_texture		*choice_txt;

	start_angle = data->direction_ang - (30 * (M_PI / 180));
	start_angle = normalize_angle(start_angle);
	increment = (60 * (M_PI / 180)) / data->mlx.w_win;
	i = 0;
	while (i < data->mlx.w_win)
	{
		horizontal_inter(data, start_angle);
		vertical_inter(data, start_angle);
		if (calculate_distance(data, data->ver_y, data->ver_x) > \
		calculate_distance(data, data->hor_y, data->hor_x))
		{
			y1 = data->hor_y;
			x1 = data->hor_x;
			data->x_offset = fmod(x1, CUB);
			if (is_up(start_angle))
				choice_txt = &data->n_txt;
			else
				choice_txt = &data->s_txt;
		}
		else
		{
			y1 = data->ver_y;
			x1 = data->ver_x;
			data->x_offset = fmod(y1, CUB);
			if (is_left(start_angle))
				choice_txt = &data->e_txt;
			else
				choice_txt = &data->w_txt;
		}
		cub_distance = calculate_distance(data, y1, x1) / CUB;
		cub_distance *= cos(data->direction_ang - start_angle);
		wall_height = data->mlx.h_win / cub_distance;
		start = (data->mlx.h_win / 2) - (wall_height / 2);
		if (start < 0)
			start = 0;
		end = (data->mlx.h_win / 2) + (wall_height / 2);
		if (end > data->mlx.h_win || end < 0)
			end = data->mlx.h_win;
		j = 0;
		while (j < start)
		{
			my_mlx_pixel_put(data, i, j, get_ceiling_c(data));
			j++;
		}
		while (j < end)
		{
			color = get_color(*choice_txt, j, data, wall_height);
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		while (j < data->mlx.h_win)
		{
			my_mlx_pixel_put(data, i, j, get_floor_c(data));
			j++;
		}
		start_angle += increment;
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
