/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:42:30 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/22 23:55:08 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

int	is_up(double ang)
{
	if (ang >= M_PI && ang <= (2 * M_PI))
		return (1);
	return (0);
}

int	is_left(double ang)
{
	if (ang >= (M_PI / 2) && ang <= ((3 * M_PI) / 2))
		return (1);
	return (0);
}

void	draw_rays_helper2(t_all *data, double *increment)
{
	data->norm.start_angle = data->direction_ang - (30 * (M_PI / 180));
	data->norm.start_angle = normalize_angle(data->norm.start_angle);
	*increment = (60 * (M_PI / 180)) / data->mlx.w_win;
}

void	draw_rays_helper1(t_all *data, int i)
{
	int	j;

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
}

void	draw_rays_helper(t_all *data, double *x1, double *y1)
{
	horizontal_inter(data, data->norm.start_angle);
	vertical_inter(data, data->norm.start_angle);
	if (calculate_distance(data, data->ver_y, data->ver_x) > \
	calculate_distance(data, data->hor_y, data->hor_x))
	{
		*y1 = data->hor_y;
		*x1 = data->hor_x;
		data->x_offset = fmod(*x1, CUB);
		if (is_up(data->norm.start_angle))
			data->norm.choice_txt = &data->n_txt;
		else
			data->norm.choice_txt = &data->s_txt;
	}
	else
	{
		*y1 = data->ver_y;
		*x1 = data->ver_x;
		data->x_offset = fmod(*y1, CUB);
		if (is_left(data->norm.start_angle))
			data->norm.choice_txt = &data->e_txt;
		else
			data->norm.choice_txt = &data->w_txt;
	}
}
