/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:46:35 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/11 18:44:31 by yaskour          ###   ########.fr       */
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
	data->mlx.win = mlx_new_window(data->mlx.mlx, 2880, 1620, "hey");
	data->mlx.img = mlx_new_image(data->mlx.mlx, 2880, 1620);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp,
			&data->mlx.line_length, &data->mlx.endian);
}
void	dda(int X0, int Y0, int X1, int Y1, t_all *data, int color)
{
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
	float	x;
	float	y;

	dx = X1 - X0;
	dy = Y1 - Y0;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	xinc = dx / (float)steps;
	yinc = dy / (float)steps;
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

	first_y = floor(data->y_player/CUB) * CUB;
	if (!is_up(ang))
		first_y += CUB;
	first_x = ((first_y - data->y_player) / tan(ang) ) + data->x_player;
	dda(floor(first_x/CUB) * CUB,first_y,(floor(first_x/CUB) * CUB) + CUB,first_y,data,0x00ff00);
	return (0);
}

int vertical_inter(t_all *data,double ang)
{
	double	first_x;
	double	first_y;

	first_x = floor(data->x_player/CUB) * CUB;
	if (!is_left(ang))
		first_x += CUB;
	first_y = data->y_player + ((first_x - data->x_player) * tan(ang));
	dda(first_x,floor(first_y/CUB) * CUB,first_x,(floor(first_y/CUB) * CUB) + CUB,data,0xff0000);
	return (0);
}

int	draw_rays(t_all *data)
{
	double	start_angle;
	double	increment;
	int		i;

	start_angle = data->direction_ang - (30 * (M_PI / 180));
	start_angle = normalize_angle(start_angle);
	increment = (60 * (M_PI / 180)) / 2280;
	i = 0;
	while (i < 1)
	{
		horizontal_inter(data,start_angle);
		vertical_inter(data,start_angle);
		dda(data->x_player, data->y_player, data->x_player
			+ cos(start_angle) * 10, data->y_player
			+ sin(start_angle) * 10, data, 0xffffff);
		start_angle += increment;
		i++;
	}
	return (0);
}

int	draw(t_all *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->valid.maps[i])
	{
		j = 0;
		while (data->valid.maps[i][j])
		{
			if (data->valid.maps[i][j] == '1')
				drawcub(data, j, i, 0x124A2A);
			if (data->valid.maps[i][j] == '0')
				drawcub(data, j, i, 0x242121);
			j++;
		}
		i++;
	}
	my_mlx_pixel_put(data, data->x_player, data->y_player, 0xffffff);
	dda(data->x_player, data->y_player, data->x_player
		+ cos(data->direction_ang) * 10, data->y_player
		+ sin(data->direction_ang) * 10, data, 0xff00ff);
	draw_rays(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (0);
}
