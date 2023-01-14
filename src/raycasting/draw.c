/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:46:35 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/14 23:38:20 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"
#include <math.h>
#include <stdio.h>

void	my_mlx_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length + x * (data->mlx.bpp
				/ 8));
	*(unsigned int *)dst = color;
}

void	init_mlx(t_all *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.w_win = 2560;
	data->mlx.h_win = 1440;
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.w_win, data->mlx.h_win, "Cub3D");
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->mlx.w_win, data->mlx.h_win);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp,
			&data->mlx.line_length, &data->mlx.endian);
}

void	dda(double X0, double Y0, double X1, double Y1, t_all *data, double color)
{
	double		dx;
	double		dy;
	double		steps;
	double	xinc;
	double	yinc;
	double	x;
	double	y;

	dx = X1 - X0;
	dy = Y1 - Y0;
	steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	xinc = dx / (double)steps;
	yinc = dy / (double)steps;
	x = X0;
	y = Y0;
	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(data, round(x), round(y), color);
		x += xinc;
		y += yinc;
	}
}

void	drawcub(t_all *data, int x, int y, unsigned int color)
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	start;

	x0 = x * CUB;
	x1 = (x + 1) * CUB;
	y0 = y * CUB;
	y1 = (y + 1) * CUB;
	while (y0 < y1)
	{
		start = x0;
		while (start < x1)
		{
			if (start == x0 || (y0 % 50) == 0)
				my_mlx_pixel_put(data,start,y0,0x000000);
			else
				my_mlx_pixel_put(data, start, y0, color);
			start++;
		}
		y0++;
	}
}

void	player_position(t_all *data, int x, int y)
{
	data->valid.player = data->valid.maps[y][x];
	data->y_player = (y * CUB) + (CUB / 2);
	data->x_player = (x * CUB) + (CUB / 2);
	data->valid.maps[(int)roundf(y)][(int)roundf(x)] = '0';
}

int is_up(double ang)
{
	if (ang >= M_PI && ang <= (2 * M_PI))
		return (1);
	return (0);
}

int is_left(double ang)
{
	if (ang >= (M_PI / 2) && ang <= ((3 * M_PI) / 2))
		return (1);
	return (0);
}

int horizontal_inter(t_all *data,double ang)
{
	double	first_x;
	double	first_y;
	double	step_y;
	double	step_x;
	int 	index_x;
	int 	index_y;

	first_y = floor(data->y_player/CUB) * CUB;
	if (!is_up(ang))
		first_y += CUB;
	first_x = ((first_y - data->y_player) / tan(ang) ) + data->x_player;

	step_y = CUB;
	if (is_up(ang))
		step_y *= -1;

	step_x = (CUB/tan(ang));
	if (!is_left(ang) && step_x < 0)
		step_x *= -1;
	if (is_left(ang) && step_x > 0)
		step_x *= -1;
	if (is_up(ang))
	{
		index_x = floor(first_x/CUB);
		index_y = floor((first_y - 1)/CUB);
	}
	else
	{
		index_x = floor(first_x/CUB);
		index_y = floor((first_y)/CUB);
	}
	while (index_y >= 0 && index_y < data->valid.map_len && index_x >= 0 && index_x < data->valid.line_len)
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
			index_x = floor(first_x/CUB);
			index_y = floor((first_y - 1)/CUB);
		}
		else
		{
			index_x = floor(first_x/CUB);
			index_y = floor((first_y)/CUB);
		}
	}
	data->hor_y = INT_MAX;
	data->hor_x = INT_MAX;
	return (0);
}

int vertical_inter(t_all *data,double ang)
{
	double	first_x;
	double	first_y;
	double 	step_x;
	double 	step_y;
	int 	index_x;
	int 	index_y;

	first_x = floor(data->x_player/CUB) * CUB;
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
		index_x = floor((first_x - 1)/CUB);
		index_y = floor(first_y/CUB);
	}
	else
	{
		index_x = floor(first_x/CUB);
		index_y = floor(first_y/CUB);
	}
	while (index_y >= 0 && index_y < data->valid.map_len && index_x >= 0 && index_x < data->valid.line_len)
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
			index_x = floor((first_x - 1)/CUB);
			index_y = floor(first_y/CUB);
		}
		else
		{
			index_x = floor(first_x/CUB);
			index_y = floor(first_y/CUB);
		}
	}
	data->ver_x = INT_MAX;
	data->ver_y = INT_MAX;
	return (0);
}

double calculate_distance(t_all *data,double y,double x)
{
	return (sqrt(pow(x - data->x_player, 2) + pow(y - data->y_player, 2)));
}

int	draw_rays(t_all *data)
{
	double	start_angle;
	double	increment;
	double 	x1;
	double 	y1;
	double 	cub_distance;
	double wall_height;
	int		i;
	int		j;
	int		start;
	int		end;
	int		color;

	start_angle = data->direction_ang - (30 * (M_PI / 180));
	start_angle = normalize_angle(start_angle);
	increment = (60 * (M_PI / 180)) / data->mlx.w_win;
	i = 0;
	while (i < data->mlx.w_win)
	{
		horizontal_inter(data,start_angle);
		vertical_inter(data,start_angle);
		if (calculate_distance(data,data->ver_y,data->ver_x) > calculate_distance(data,data->hor_y, data->hor_x))
		{
			y1 = data->hor_y;
			x1 = data->hor_x;
			color = 0xff;
		}
		else
		{
			y1 = data->ver_y;
			x1 = data->ver_x;
			color = 0xffffff;
		}
		cub_distance = calculate_distance(data,y1,x1)/ CUB;
		cub_distance *= cos(data->direction_ang - start_angle);
		wall_height = data->mlx.h_win / cub_distance;
		j = 0;
		while (j < (data->mlx.h_win/2))
		{
			my_mlx_pixel_put(data,i,j,0x000000);
			j++;
		}
		start = (data->mlx.h_win/2) - (wall_height/2);
		if (start < 0)
			start = 0;
		end = (data->mlx.h_win/2) + (wall_height/2);
		if (end > data->mlx.h_win)
			end = data->mlx.h_win;
		j = start;
		while (j < end)
		{
			my_mlx_pixel_put(data,i,j,color);
			j++;
		}
		while(j < data->mlx.h_win)
		{
			my_mlx_pixel_put(data,i,j,0xff00ff);
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
