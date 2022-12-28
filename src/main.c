/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:07:03 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/28 17:42:15 by yaskour          ###   ########.fr       */
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
  free_textures(data);
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
    while (data.valid.maps[i])
    {
      printf("%s\n",data.valid.maps[i]);
      free(data.valid.maps[i++]);
    }
    free(data.valid.maps);
    return (0);
  }
  else
    printf("number of args is not valid\n");
  return (0);
}
