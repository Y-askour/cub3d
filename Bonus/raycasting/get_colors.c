/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:38:25 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/23 00:39:42 by zyacoubi         ###   ########.fr       */
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
