/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:43:15 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/22 23:47:59 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

void	my_mlx_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length + x * (data->mlx.bpp
				/ 8));
	*(unsigned int *)dst = color;
}

void	load_textures_helper(t_all *data)
{
	data->e_txt.img = mlx_xpm_file_to_image(data->mlx.mlx, data->valid.ea, \
			&data->e_txt.width, &data->e_txt.height);
	if (!data->e_txt.img)
		exit(1);
	data->e_txt.addr = (int *) mlx_get_data_addr(data->e_txt.img, \
			&data->e_txt.bpp, &data->e_txt.line_length, &data->e_txt.endian);
	data->w_txt.img = mlx_xpm_file_to_image(data->mlx.mlx, data->valid.we, \
			&data->w_txt.width, &data->w_txt.height);
	if (!data->w_txt.img)
		exit(1);
	data->w_txt.addr = (int *) mlx_get_data_addr(data->w_txt.img, \
			&data->w_txt.bpp, &data->w_txt.line_length, &data->w_txt.endian);
	data->n_txt.img = mlx_xpm_file_to_image(data->mlx.mlx, data->valid.no, \
			&data->n_txt.width, &data->n_txt.height);
	if (!data->n_txt.img)
		exit(1);
	data->n_txt.addr = (int *) mlx_get_data_addr(data->n_txt.img, \
			&data->n_txt.bpp, &data->n_txt.line_length, &data->n_txt.endian);
	data->s_txt.img = mlx_xpm_file_to_image(data->mlx.mlx, \
			data->valid.so, &data->s_txt.width, &data->s_txt.height);
	if (!data->s_txt.img)
		exit(1);
}

void	load_textures_helper1(t_all *data)
{
	data->s_txt.addr = (int *) mlx_get_data_addr(data->s_txt.img, \
			&data->s_txt.bpp, &data->s_txt.line_length, &data->s_txt.endian);
	data->gun_1_txt.img = mlx_xpm_file_to_image(data->mlx.mlx, \
			"./gun_sprites/1.xpm", &data->gun_1_txt.width, \
			&data->gun_1_txt.height);
	if (!data->gun_1_txt.img)
		exit(1);
	data->gun_1_txt.addr = (int *) mlx_get_data_addr(data->gun_1_txt.img, \
			&data->gun_1_txt.bpp, &data->gun_1_txt.line_length, \
			&data->gun_1_txt.endian);
	data->gun_2_txt.img = mlx_xpm_file_to_image(data->mlx.mlx, \
			"./gun_sprites/2.xpm", &data->gun_2_txt.width, \
			&data->gun_2_txt.height);
	if (!data->gun_2_txt.img)
		exit(1);
}

void	load_textures(t_all *data)
{
	load_textures_helper(data);
	load_textures_helper1(data);
	data->gun_2_txt.addr = (int *) mlx_get_data_addr(data->gun_2_txt.img, \
			&data->gun_2_txt.bpp, &data->gun_2_txt.line_length, \
			&data->gun_2_txt.endian);
	data->gun_3_txt.img = mlx_xpm_file_to_image(data->mlx.mlx, \
			"./gun_sprites/3.xpm", &data->gun_3_txt.width, \
			&data->gun_3_txt.height);
	if (!data->gun_3_txt.img)
		exit(1);
	data->gun_3_txt.addr = (int *) mlx_get_data_addr(data->gun_3_txt.img, \
			&data->gun_3_txt.bpp, &data->gun_3_txt.line_length, \
			&data->gun_3_txt.endian);
	data->minimap.img = mlx_xpm_file_to_image(data->mlx.mlx, \
			"./textures/minimap.xpm", &data->minimap.width, \
			&data->minimap.height);
	if (!data->minimap.img)
		exit(1);
	data->minimap.addr = (int *) mlx_get_data_addr(data->minimap.img, \
			&data->minimap.bpp, &data->minimap.line_length, \
			&data->minimap.endian);
}

void	init_mlx(t_all *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.w_win = 2560 / 2;
	data->mlx.h_win = 1440 / 2;
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.w_win, \
	data->mlx.h_win, "Cub3D_bonus");
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->mlx.w_win, \
	data->mlx.h_win);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp,
			&data->mlx.line_length, &data->mlx.endian);
	ft_bzero(&data->key, sizeof(data->key));
	load_textures(data);
}
