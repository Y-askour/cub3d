/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:12:26 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/20 16:56:23 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	is_up(double ang)
{
	if (ang >= M_PI && ang <= (2 * M_PI))
		return (1);
	return (0);
}

int	is_left(double ang)
{
	if (ang >= (M_PI / 2) && ang <= ((3 * M_PI) / 2))
		return (1);
	return (0);
}

unsigned int	get_floor_c(t_all *data)
{
	return (data->valid.floor[0] * 65536 + \
	data->valid.floor[1] * 256 + data->valid.floor[2]);
}

double	calculate_distance(t_all *data, double y, double x)
{
	return (sqrt(pow(x - data->x_player, 2) + pow(y - data->y_player, 2)));
}

unsigned int	get_ceiling_c(t_all *data)
{
	return (data->valid.ceiling[0] * 65536 + \
	data->valid.ceiling[1] * 256 + data->valid.ceiling[2]);
}
