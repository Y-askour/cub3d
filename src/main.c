/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:42 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/03 18:16:11 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/include.h"
#include <stdio.h>

int check(t_all *data)
{
  if (check_colors(data))
    return (1);
  if (check_textures(data))
  {
    free_map(data);
    free_textures(data);
    return (1);
  }
  if (check_map(data))
  {
    free_textures(data);
    return (1);
  }
  return (0);
}

int check_wall(t_all *data,int y,int x)
{

	x /= CUB;
	y /= CUB;
	if (data->valid.maps[y][x] == '1')
		return (1);
	return (0);
}

int younes(int keycode,t_all *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
	{
		data->direction_ang -= M_PI/30;
	}
	else if (keycode == 124)
	{
		data->direction_ang += M_PI/30;
	}
	else if (keycode == 13) // w
	{
		data->x_player += 10 * cos(data->direction_ang);
		data->y_player += 10 * sin(data->direction_ang);
		//if (!check_wall(data,data->y_player + 1,data->x_player))
	}
	else if (keycode == 1) // s
	{
		data->x_player -= 10 * cos(data->direction_ang);
		data->y_player -= 10 * sin(data->direction_ang);
		//if (!check_wall(data,data->y_player + 1,data->x_player))
	}
	else if (keycode == 0) // a
	{
		data->x_player += 10  * sin(data->direction_ang);
		data->y_player -= 10  * cos(data->direction_ang);
		//if (!check_wall(data,data->y_player,data->x_player - 1))
	}
	else if (keycode == 2) // d
	{
		data->x_player -= 10  * sin(data->direction_ang);
		data->y_player += 10  * cos(data->direction_ang);
		//if (!check_wall(data,data->y_player,data->x_player + 1))
	}
	draw(data);
	return (0);
}

int test(int keycode,t_all *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	if (keycode == 124)
		printf("keycode\n");
	return (0);
}

int main(int ac,char **av)
{
  t_all data;
  int i;

  i = 0;
  if (ac == 2)
  {
    if (!parssing(av[1],&data))
    {
      return (1);
    }
    if (check(&data))
      return (1);
	init_mlx(&data);
	draw(&data);
    //i = 0;
    //while (data.valid.maps[i])
	//	free(data.valid.maps[i++]);
	//free(data.valid.maps);
	//free(data.valid.we);
	//free(data.valid.so);
	//free(data.valid.ea);
	//free(data.valid.no);
	mlx_hook(data.mlx.win, 2, 1L<<0, younes,&data);
	//mlx_hook(data.mlx.win, 3, 1L<<1, test, NULL);
	mlx_loop(data.mlx.mlx);
    return (0);
  }
  else
    printf("number of args is not valid\n");
  return (0);
}
