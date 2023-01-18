/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:11:54 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/18 16:04:55 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	init_mlx(t_all *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.w_win = 2560/2;
	data->mlx.h_win = 1440/2;
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.w_win , \
	data->mlx.h_win, "Cub3D");
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->mlx.w_win, \
	data->mlx.h_win);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp,
			&data->mlx.line_length, &data->mlx.endian);
}
