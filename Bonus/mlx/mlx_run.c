/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:40:27 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/23 00:40:39 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

void	run(t_all *data)
{
	mlx_mouse_move(data->mlx.win, data->mlx.w_win / 2, data->mlx.h_win / 2);
	mlx_mouse_hide();
	mlx_hook(data->mlx.win, DESTROY, (1L << 17), mlx_close, data);
	mlx_hook(data->mlx.win, KEY_RELEASE, 0, mlx_key_release, data);
	mlx_hook(data->mlx.win, KEY_PRESS, 0, mlx_key, data);
	mlx_hook(data->mlx.win, MOUSEMOVE, 0, mouse_move, data);
	mlx_loop_hook(data->mlx.mlx, mlx_keypress, data);
	mlx_loop(data->mlx.mlx);
}
