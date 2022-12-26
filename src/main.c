/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:07:03 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/25 19:01:05 by yaskour          ###   ########.fr       */
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
    free_metadata(&data);
    i = 0;
    while(data.parss.map[i])
      free(data.parss.map[i++]);
    free(data.parss.map);
    return (0);
  }
  else
    printf("number of args is not valid\n");
  return (0);
}
