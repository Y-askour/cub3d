/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:12:26 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/22 23:54:41 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

unsigned int	get_color(t_texture txt, double y, t_all *data, \
		double wall_height)
{
	unsigned int	color;
	int				y_offset;
	int				x_offset;

	y_offset = y + (wall_height / 2) - (data->mlx.h_win / 2 - data->new_pov);
	x_offset = (data->x_offset / CUB) * txt.width;
	y_offset = ((y_offset) * ((double)txt.height / \
				wall_height));
	color = txt.addr[abs((y_offset * txt.height) + x_offset)];
	return ((unsigned int)color);
}

double	calculate_distance(t_all *data, double y, double x)
{
	return (sqrt(pow(x - data->x_player, 2) + pow(y - data->y_player, 2)));
}
