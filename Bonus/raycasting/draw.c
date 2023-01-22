/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:46:35 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/23 00:25:05 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

unsigned int	get_floor_c(t_all *data)
{
	return (data->valid.floor[0] * 65536 + data->valid.floor[1] \
			* 256 + data->valid.floor[2]);
}

unsigned int	get_ceiling_c(t_all *data)
{
	return (data->valid.ceiling[0] * 65536 + data->valid.ceiling[1] \
			* 256 + data->valid.ceiling[2]);
}

void	player_position(t_all *data, int x, int y, int *player)
{
	data->valid.player = data->valid.maps[y][x];
	data->y_player = (y * CUB) + (CUB / 2);
	data->x_player = (x * CUB) + (CUB / 2);
	data->valid.maps[(int)roundf(y)][(int)roundf(x)] = '0';
	*player = *player + 1;
}

void	draw_rays_helper3(t_all *data)
{
	data->norm.start = (data->mlx.h_win / 2) - (data->norm.wall_height / 2) \
					- data->new_pov;
	if (data->norm.start < 0)
		data->norm.start = 0;
	data->norm.end = (data->mlx.h_win / 2) + (data->norm.wall_height / 2) \
					- data->new_pov;
	if (data->norm.end > data->mlx.h_win || data->norm.end < 0)
		data->norm.end = data->mlx.h_win;
}

int	draw_rays(t_all *data)
{
	int				i;
	double			increment;
	double			x1;
	double			y1;

	draw_rays_helper2(data, &increment);
	i = -1;
	while (++i < data->mlx.w_win)
	{
		draw_rays_helper(data, &x1, &y1);
		data->norm.cub_distance = calculate_distance(data, y1, x1) / CUB;
		data->norm.cub_distance *= cos(data->direction_ang - \
				data->norm.start_angle);
		data->norm.wall_height = data->mlx.h_win / data->norm.cub_distance;
		draw_rays_helper3(data);
		draw_rays_helper1(data, i);
		data->norm.start_angle += increment;
	}
	return (0);
}

void	draw_gun(t_all *data)
{
	static int	i;

	data->gun_frame = NULL;
	if (data->shot_)
	{
		if (i >= 0 && i < 6)
			data->gun_frame = &data->gun_1_txt;
		else if (i >= 6 && i < 12)
			data->gun_frame = &data->gun_2_txt;
		else if (i >= 12 && i < 18)
			data->gun_frame = &data->gun_3_txt;
		if (i == 18)
		{
			i = 0;
			data->shot_ = 0;
			data->gun_frame = &data->gun_1_txt;
			return ;
		}
		i++;
	}
	else if (data->shot_ == 0)
		data->gun_frame = &data->gun_1_txt;
}

int	draw(t_all *data)
{
	int			x0;
	int			y0;

	draw_gun(data);
	draw_rays(data);
	y0 = data->mlx.h_win - data->gun_frame->height;
	x0 = data->mlx.w_win / 2 - (data->gun_frame->width / 2);
	render_minimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, \
			data->gun_frame->img, x0, y0);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, \
			data->minimap.img, -20, -20);
	return (0);
}
