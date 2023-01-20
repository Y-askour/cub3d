/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:56:04 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/20 17:17:40 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

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
				my_mlx_pixel_put(data, start, y0, 0x000000);
			else
				my_mlx_pixel_put(data, start, y0, color);
			start++;
		}
		y0++;
	}
}

unsigned int	get_color(t_texture txt, double y, t_all *data, double wall_h)
{
	int				y_offset;
	unsigned int	color;
	int				x_offset;

	y_offset = y + (wall_h / 2) - (data->mlx.h_win / 2);
	x_offset = (data->x_offset / CUB) * txt.width;
	y_offset = ((y_offset) * ((double)txt.height / \
				wall_h));
	color = txt.addr[(y_offset * txt.height) + x_offset];
	return ((unsigned int)color);
}
