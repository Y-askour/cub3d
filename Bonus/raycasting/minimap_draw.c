/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:42:56 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/22 23:58:45 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

void	draw_miniplayer(t_all *data, double x, double y, int color)
{
	int	i;
	int	j;

	i = y - 1;
	while (++i < y + 3)
	{
		j = x - 1;
		while (++j < x + 3)
		{
			if (i >= 0 && j >= 0 && i < 200 && j < 200)
				my_mlx_pixel_put(data, j, i, color);
		}
	}
}

void	draw_circle(t_all *data, double y, double x, int color)
{
	int	i;
	int	j;

	i = y - 1;
	while (++i < y + CUB)
	{
		j = x - 1;
		while (++j < x + CUB)
		{
			if (i >= 0 && j >= 0 && i < 200 && j < 200)
				if (sqrt(powf(i / 12.5 - 8, 2) + powf(j / 12.5 - 8, 2)) < 8)
					my_mlx_pixel_put(data, j, i, color);
		}
	}
}

void	render_minimap(t_all *data)
{
	int		i;
	int		j;
	double	dx;
	double	dy;	

	dx = data->x_player - 100;
	dy = data->y_player - 100;
	i = -1;
	while (data->valid.maps[++i])
	{
		j = -1;
		while (data->valid.maps[i][++j])
		{
			if (data->valid.maps[i][j] == '1')
				draw_circle(data, (i * CUB - dy), \
				(j * CUB - dx), 0x000000);
		}
	}
	draw_miniplayer(data, (data->x_player - dx - 1), \
	(data->y_player - dy - 1), 0xff0000);
}
