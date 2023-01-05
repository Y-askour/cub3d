/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:46:35 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/05 17:20:07 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <include.h>

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
	int x0;
	int	x1;
	int y0;
	int y1;
	int start;

	x0 = x * CUB;
	x1 = (x + 1) * CUB;
	y0 = y * CUB;
	y1 = (y + 1) * CUB;
	while (y0 < y1)
	{
		start = x0;
		while (start < x1)
		{
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
	data->valid.maps[y][x] = '0';
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
				drawcub(data, j, i, 0x475E6B);
			j++;
		}
		i++;
	}
	my_mlx_pixel_put(data, data->x_player, data->y_player, 0xffffff);
	dda(data->x_player, data->y_player, data->x_player
		+ cos(data->direction_ang) * 20, data->y_player
		+ sin(data->direction_ang) * 20, data, 0xffffff);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (0);
}
