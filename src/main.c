/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:07:03 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/26 22:37:07 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/include.h"

int check(t_all *data)
{
  if (check_colors(data))
    return (1);
  if (check_textures(data))
  {
    free_textures(data);
    return (1);
  }
  if (check_map(data))
  {
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
    {
      return (1);
    }
    while (data.parss.all[i])
      free(data.parss.all[i++]);
    free(data.parss.all);
    i = 0;
    while (data.parss.map[i])
      free(data.parss.map[i++]);
    free(data.parss.map);
    i = 0;
    while (data.valid.maps[i])
    {
      printf("%s\n",data.valid.maps[i]);
      free(data.valid.maps[i++]);
    }
    free(data.valid.maps);

    free(data.parss.floor);
    free(data.parss.ceiling);
    free(data.valid.no);
    free(data.valid.so);
    free(data.valid.we);
    free(data.valid.ea);
    return (0);
  }
  else
    printf("number of args is not valid\n");
  return (0);
}
