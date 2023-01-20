/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:46:35 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/20 03:07:26 by zyacoubi         ###   ########.fr       */
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

unsigned int get_color(t_texture txt,double y,t_all *data,double wall_height)
{
	int y_offset;
	unsigned int color;
	int x_offset;

	y_offset = y + (wall_height / 2) - (data->mlx.h_win / 2 - data->new_pov);
	x_offset = (data->x_offset / CUB) * txt.width;
	y_offset = ((y_offset) * ((double)txt.height / \
				wall_height));
	color = txt.addr[(y_offset * txt.height) +x_offset];
	return ((unsigned int)color);
}

unsigned get_floor_c(t_all *data)
{
	return (data->valid.floor[0] * 65536 + data->valid.floor[1] * 256 + data->valid.floor[2]);
}

unsigned get_ceiling_c(t_all *data)
{
	return (data->valid.ceiling[0] * 65536 + data->valid.ceiling[1] * 256 + data->valid.ceiling[2]);
}

/*void	dda(double X0, double Y0, double X1, double Y1, t_all *data, double 
 * color)
{
	double		dx;
	double		dy;
	double		steps;
	double	xinc;
	double	yinc;
	double	x;
	double	y;

	dx = X1 - X0;
	dy = Y1 - Y0;
	steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	xinc = dx / (double)steps;
	yinc = dy / (double)steps;
	x = X0;
	y = Y0;
	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(data, round(x), round(y), color);
		x += xinc;
		y += yinc;
	}
}*/

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

void	player_position(t_all *data, int x, int y , int *player)
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

int	horizontal_inter(t_all *data, double ang)
{
	double	first_x;
	double	first_y;
	double	step_y;
	double	step_x;
	int		index_x;
	int		index_y;

	first_y = floor(data->y_player / CUB) * CUB;
	if (!is_up(ang))
		first_y += CUB;
	first_x = ((first_y - data->y_player) / tan(ang)) + data->x_player;
	step_y = CUB;
	if (is_up(ang))
		step_y *= -1;
	step_x = (CUB / tan(ang));
	if (!is_left(ang) && step_x < 0)
		step_x *= -1;
	if (is_left(ang) && step_x > 0)
		step_x *= -1;
	if (is_up(ang))
	{
		index_x = floor(first_x / CUB);
		index_y = floor((first_y - 1) / CUB);
	}
	else
	{
		index_x = floor(first_x / CUB);
		index_y = floor((first_y) / CUB);
	}
	while (index_y >= 0 && index_y < data->valid.map_len && index_x >= 0 && index_x < data->valid.line_len)
	{
		if (data->valid.maps[index_y][index_x] == '1')
		{
			data->hor_x = first_x;
			data->hor_y = first_y;
			return (0);
		}
		first_x += step_x;
		first_y += step_y;
		if (is_up(ang))
		{
			index_x = floor(first_x / CUB);
			index_y = floor((first_y - 1) / CUB);
		}
		else
		{
			index_x = floor(first_x / CUB);
			index_y = floor((first_y) / CUB);
		}
	}
	data->hor_y = INT_MAX;
	data->hor_x = INT_MAX;
	return (0);
}

int	vertical_inter(t_all *data, double ang)
{
	double	first_x;
	double	first_y;
	double	step_x;
	double	step_y;
	int		index_x;
	int		index_y;

	first_x = floor(data->x_player / CUB) * CUB;
	if (!is_left(ang))
		first_x += CUB;
	first_y = data->y_player + ((first_x - data->x_player) * tan(ang));
	step_x = CUB;
	if (is_left(ang))
		step_x *= -1;
	step_y = tan(ang) * CUB;
	if (is_up(ang) && step_y > 0)
		step_y *= -1;
	if (!is_up(ang) && step_y < 0)
		step_y *= -1;
	if (is_left(ang))
	{
		index_x = floor((first_x - 1) / CUB);
		index_y = floor(first_y / CUB);
	}
	else
	{
		index_x = floor(first_x / CUB);
		index_y = floor(first_y / CUB);
	}
	while (index_y >= 0 && index_y < data->valid.map_len && index_x >= 0 && index_x < data->valid.line_len)
	{
		if (data->valid.maps[index_y][index_x] == '1')
		{
			data->ver_x = first_x;
			data->ver_y = first_y;
			return (0);
		}
		first_x += step_x;
		first_y += step_y;
		if (is_left(ang))
		{
			index_x = floor((first_x - 1) / CUB);
			index_y = floor(first_y / CUB);
		}
		else
		{
			index_x = floor(first_x / CUB);
			index_y = floor(first_y / CUB);
		}
	}
	data->ver_x = INT_MAX;
	data->ver_y = INT_MAX;
	return (0);
}

double	calculate_distance(t_all *data, double y, double x)
{
	return (sqrt(pow(x - data->x_player, 2) + pow(y - data->y_player, 2)));
}

int	draw_rays(t_all *data)
{
	double	start_angle;
	double	increment;
	double	x1;
	double	y1;
	double	cub_distance;
	double	wall_height;
	int		i;
	int		j;
	int		start;
	int		end;
	unsigned int		color;
	t_texture	*choice_txt;

	start_angle = data->direction_ang - (30 * (M_PI / 180));
	start_angle = normalize_angle(start_angle);
	increment = (60 * (M_PI / 180)) / data->mlx.w_win;
	i = 0;
	while (i < data->mlx.w_win)
	{
		horizontal_inter(data, start_angle);
		vertical_inter(data, start_angle);
		if (calculate_distance(data, data->ver_y, data->ver_x) > calculate_distance(data, data->hor_y, data->hor_x))
		{
			y1 = data->hor_y;
			x1 = data->hor_x;
			data->x_offset = fmod(x1,CUB);
			if (is_up(start_angle))
				choice_txt = &data->n_txt;
			else
				choice_txt = &data->s_txt;
		}
		else
		{
			y1 = data->ver_y;
			x1 = data->ver_x;
			data->x_offset = fmod(y1,CUB);
			if (is_left(start_angle))
				choice_txt = &data->e_txt;
			else
				choice_txt = &data->w_txt;
		}
		cub_distance = calculate_distance(data, y1, x1) / CUB;
		cub_distance *= cos(data->direction_ang - start_angle);
		wall_height = data->mlx.h_win / cub_distance;
		start = (data->mlx.h_win / 2) - (wall_height / 2) - data->new_pov;
		if (start < 0)
			start = 0;
		end = (data->mlx.h_win / 2) + (wall_height / 2) - data->new_pov;
		if (end > data->mlx.h_win || end < 0)
			end = data->mlx.h_win;
		j = 0;
		while (j < start)
		{
			my_mlx_pixel_put(data, i, j, get_ceiling_c(data));
			j++;
		}
		j = start;
		while (j < end)
		{
			color = get_color(*choice_txt,j,data,wall_height); 
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		j = end;
		while (j < data->mlx.h_win)
		{
			my_mlx_pixel_put(data, i, j, get_floor_c(data));
			j++;
		}
		start_angle += increment;
		i++;
	}
	return (0);
}

int	draw(t_all *data)
{
	draw_rays(data);
	render_minimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (0);
}
