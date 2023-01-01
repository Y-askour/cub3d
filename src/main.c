/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:42 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/01 16:25:31 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/include.h"

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
    printf("%s\n",data.valid.so);
    printf("%s\n",data.valid.no);
    printf("%s\n",data.valid.we);
    printf("%s\n",data.valid.ea);
    i = 0;
    while (i < 3)
      printf("ceiling %d\n",data.valid.ceiling[i++]);
    i = 0;
    while (i < 3)
      printf("%d\n",data.valid.floor[i++]);
    i = 0;
    while (data.valid.maps[i])
	{
		printf("%s\n",data.valid.maps[i]);
		free(data.valid.maps[i++]);
	}
	free(data.valid.maps);
	free(data.valid.ceiling);
	free(data.valid.floor);
	free(data.valid.we);
	free(data.valid.so);
	free(data.valid.ea);
	free(data.valid.no);
    return (0);
  }
  else
    printf("number of args is not valid\n");
  return (0);
}
