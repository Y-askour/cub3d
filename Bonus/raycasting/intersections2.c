/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:49:54 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/22 23:49:57 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

void	horizontal_inter_init(t_all *data, double ang)
{
	data->norm.first_y = floor(data->y_player / CUB) * CUB;
	if (!is_up(ang))
		data->norm.first_y += CUB;
	data->norm.first_x = ((data->norm.first_y - data->y_player) / \
			tan(ang)) + data->x_player;
	data->norm.step_y = CUB;
	if (is_up(ang))
		data->norm.step_y *= -1;
	data->norm.step_x = (CUB / tan(ang));
	if (!is_left(ang) && data->norm.step_x < 0)
		data->norm.step_x *= -1;
	if (is_left(ang) && data->norm.step_x > 0)
		data->norm.step_x *= -1;
}
