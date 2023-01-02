/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:46:35 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/02 17:35:01 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;
	dst = data->mlx.addr + (y * data->mlx.line_length + x * (data->mlx.bpp / 8));
	*(unsigned int*)dst = color;
}

void 	init_mlx(t_all *data)
{

	data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx,1000,1000,"hey");
	data->mlx.img = mlx_new_image(data->mlx.mlx,1000,1000);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img,&data->mlx.bpp,&data->mlx.line_length,&data->mlx.endian);
}

void dda(int X0, int Y0, int X1, int Y1,t_all *data,int color)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        my_mlx_pixel_put(data,round(X), round(Y),color); 
        X += Xinc; 
        Y += Yinc;
    }
}

void drawcub(t_all *data , int x , int y,unsigned int color)
{
	int x0 = x * CUB;
	int x1 = (x + 1) * CUB;
	int y0 = y * CUB;
	int y1 = (y + 1) * CUB;

	int start;
	while(y0 < y1)
	{
		start = x0;
		while (start < x1)
		{
			my_mlx_pixel_put(data,start,y0,color);
			start++;
		}
		y0++;
	}
}

void	player_position(t_all *data,int x,int y)
{
	data->y_player = (y * CUB) + (CUB / 2);
	data->x_player = (x * CUB) + (CUB / 2);
	data->valid.maps[y][x] = '0';
}

int draw(t_all *data)
{
	int i;
	int j;

	i = 0;
	while (data->valid.maps[i])
	{
		j = 0;
		while(data->valid.maps[i][j])
		{
			if (data->valid.maps[i][j] == '1')
				drawcub(data,j,i,0x124A2A);
			if (data->valid.maps[i][j] == '0')
				drawcub(data,j,i,0x475E6B);
			j++;
		}
		i++;
	}
	my_mlx_pixel_put(data, data->x_player,data->y_player,0xffffff);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (0);
}
