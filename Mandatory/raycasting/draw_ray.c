/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:56:04 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/22 19:17:38 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

unsigned int	get_color(t_texture txt, double y, t_all *data, double wall_h)
{
	int				y_offset;
	unsigned int	color;
	int				x_offset;

	y_offset = y + (wall_h / 2) - (data->mlx.h_win / 2);
	x_offset = (data->x_offset / CUB) * txt.width;
	y_offset = ((y_offset) * ((double)txt.height / \
				wall_h));
	color = txt.addr[abs((y_offset * txt.height) + x_offset)];
	return ((unsigned int)color);
}
