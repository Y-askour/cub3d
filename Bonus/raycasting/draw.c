/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:46:35 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/22 23:24:12 by yaskour          ###   ########.fr       */
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

void	draw_miniplayer(t_all *r, double x, double y, int color)
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
				my_mlx_pixel_put(r, j, i, color);
		}
	}
}

void	draw_square(t_all *r, double y, double x, int color)
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
					my_mlx_pixel_put(r, j, i, color);
		}
	}
}

void	render_minimap(t_all *r)
{
	int		i;
	int		j;
	double	dx;
	double	dy;	

	dx = r->x_player - 100;
	dy = r->y_player - 100;
	i = -1;
	while (r->valid.maps[++i])
	{
		j = -1;
		while (r->valid.maps[i][++j])
		{
			if (r->valid.maps[i][j] == '1')
				draw_square(r, (i * CUB - dy), \
				(j * CUB - dx), 0x000000);
		}
	}
	draw_miniplayer(r, (r->x_player - dx - 1), \
	(r->y_player - dy - 1), 0xff0000);
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

void	player_position(t_all *data, int x, int y, int *player)
{
	data->valid.player = data->valid.maps[y][x];
	data->y_player = (y * CUB) + (CUB / 2);
	data->x_player = (x * CUB) + (CUB / 2);
	data->valid.maps[(int)roundf(y)][(int)roundf(x)] = '0';
	*player = *player + 1;
}

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

void	horizontal_inter_helper(t_all *data, double ang, \
		int *index_x, int *index_y)
{
	if (is_up(ang))
	{
		*index_x = floor(data->norm.first_x / CUB);
		*index_y = floor((data->norm.first_y - 1) / CUB);
	}
	else
	{
		*index_x = floor(data->norm.first_x / CUB);
		*index_y = floor((data->norm.first_y) / CUB);
	}
}

void	horizontal_inter(t_all *data, double ang)
{
	int		index_x;
	int		index_y;

	horizontal_inter_init(data, ang);
	horizontal_inter_helper(data, ang, &index_x, &index_y);
	while (index_y >= 0 && index_y < data->valid.map_len \
	&& index_x >= 0 && index_x < data->valid.line_len)
	{
		if (data->valid.maps[index_y][index_x] == '1')
		{
			data->hor_x = data->norm.first_x;
			data->hor_y = data->norm.first_y;
			return ;
		}
		data->norm.first_x += data->norm.step_x;
		data->norm.first_y += data->norm.step_y;
		horizontal_inter_helper(data, ang, &index_x, &index_y);
	}
	data->hor_y = INT_MAX;
	data->hor_x = INT_MAX;
	return ;
}

void	vertical_inter_init(t_all *data, double ang)
{
	data->norm.first_x = floor(data->x_player / CUB) * CUB;
	if (!is_left(ang))
		data->norm.first_x += CUB;
	data->norm.first_y = data->y_player + ((data->norm.first_x - \
				data->x_player) * tan(ang));
	data->norm.step_x = CUB;
	if (is_left(ang))
		data->norm.step_x *= -1;
	data->norm.step_y = tan(ang) * CUB;
	if (is_up(ang) && data->norm.step_y > 0)
		data->norm.step_y *= -1;
	if (!is_up(ang) && data->norm.step_y < 0)
		data->norm.step_y *= -1;
}

void	vertical_inter_helper(t_all *data, double ang, int *index_y, \
		int *index_x)
{
	if (is_left(ang))
	{
		*index_x = floor((data->norm.first_x - 1) / CUB);
		*index_y = floor(data->norm.first_y / CUB);
	}
	else
	{
		*index_x = floor(data->norm.first_x / CUB);
		*index_y = floor(data->norm.first_y / CUB);
	}
}

void	vertical_inter(t_all *data, double ang)
{
	int		index_x;
	int		index_y;

	vertical_inter_init(data, ang);
	vertical_inter_helper(data, ang, &index_y, &index_x);
	while (index_y >= 0 && index_y < data->valid.map_len \
	&& index_x >= 0 && index_x < data->valid.line_len)
	{
		if (data->valid.maps[index_y][index_x] == '1')
		{
			data->ver_x = data->norm.first_x;
			data->ver_y = data->norm.first_y;
			return ;
		}
		data->norm.first_x += data->norm.step_x;
		data->norm.first_y += data->norm.step_y;
		vertical_inter_helper(data, ang, &index_y, &index_x);
	}
	data->ver_x = INT_MAX;
	data->ver_y = INT_MAX;
	return ;
}

double	calculate_distance(t_all *data, double y, double x)
{
	return (sqrt(pow(x - data->x_player, 2) + pow(y - data->y_player, 2)));
}

void	draw_rays_helper(t_all *data, double *x1, double *y1)
{
	horizontal_inter(data, data->norm.start_angle);
	vertical_inter(data, data->norm.start_angle);
	if (calculate_distance(data, data->ver_y, data->ver_x) > \
	calculate_distance(data, data->hor_y, data->hor_x))
	{
		*y1 = data->hor_y;
		*x1 = data->hor_x;
		data->x_offset = fmod(*x1, CUB);
		if (is_up(data->norm.start_angle))
			data->norm.choice_txt = &data->n_txt;
		else
			data->norm.choice_txt = &data->s_txt;
	}
	else
	{
		*y1 = data->ver_y;
		*x1 = data->ver_x;
		data->x_offset = fmod(*y1, CUB);
		if (is_left(data->norm.start_angle))
			data->norm.choice_txt = &data->e_txt;
		else
			data->norm.choice_txt = &data->w_txt;
	}
}

void	draw_rays_helper1(t_all *data, int i)
{
	int	j;

	j = 0;
	while (j < data->norm.start)
	{
		my_mlx_pixel_put(data, i, j, get_ceiling_c(data));
		j++;
	}
	while (j < data->norm.end)
	{
		data->norm.color = get_color(*data->norm.choice_txt, j, data, \
				data->norm.wall_height);
		my_mlx_pixel_put(data, i, j, data->norm.color);
		j++;
	}
	while (j < data->mlx.h_win)
	{
		my_mlx_pixel_put(data, i, j, get_floor_c(data));
		j++;
	}
}

void	draw_rays_helper2(t_all *data, double *increment)
{
	data->norm.start_angle = data->direction_ang - (30 * (M_PI / 180));
	data->norm.start_angle = normalize_angle(data->norm.start_angle);
	*increment = (60 * (M_PI / 180)) / data->mlx.w_win;
}

int	draw_rays(t_all *data)
{
	int				i;
	double			increment;
	double			x1;
	double			y1;

	draw_rays_helper2(data, &increment);
	i = -1;
	while (++i < data->mlx.w_win)
	{
		draw_rays_helper(data, &x1, &y1);
		data->norm.cub_distance = calculate_distance(data, y1, x1) / CUB;
		data->norm.cub_distance *= cos(data->direction_ang - \
				data->norm.start_angle);
		data->norm.wall_height = data->mlx.h_win / data->norm.cub_distance;
		data->norm.start = (data->mlx.h_win / 2) - (data->norm.wall_height / 2) \
						- data->new_pov;
		if (data->norm.start < 0)
			data->norm.start = 0;
		data->norm.end = (data->mlx.h_win / 2) + (data->norm.wall_height / 2) \
						- data->new_pov;
		if (data->norm.end > data->mlx.h_win || data->norm.end < 0)
			data->norm.end = data->mlx.h_win;
		draw_rays_helper1(data, i);
		data->norm.start_angle += increment;
	}
	return (0);
}

int	draw(t_all *data)
{
	t_texture	*gun_frame;
	static int	i;
	int			x0;
	int			y0;

	gun_frame = NULL;
	if (data->shot_)
	{
		if (i >= 0 && i < 6)
		{
			gun_frame = &data->gun_1_txt;
			i++;
		}
		else if (i >= 6 && i < 12)
		{
			gun_frame = &data->gun_2_txt;
			i++;
		}
		else if (i >= 12 && i < 18)
		{
			gun_frame = &data->gun_3_txt;
			i++;
		}
		if (i == 18)
		{
			i = 0;
			data->shot_ = 0;
		}
	}
	else if (data->shot_ == 0)
		gun_frame = &data->gun_1_txt;
	draw_rays(data);
	y0 = data->mlx.h_win - gun_frame->height;
	x0 = data->mlx.w_win / 2 - (gun_frame->width / 2);
	render_minimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, \
			gun_frame->img, x0, y0);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, \
			data->minimap.img, -20, -20);
	return (0);
}
