/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:30:04 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/29 20:49:42 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int cout_comma(char *str)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (str[i])
  {
    if (str[i] == ',')
      j++;
    i++;
  }
  return (j);
}

int check_is_rgb(char **rgb)
{
  int i;
  int j;
  int number;

  i = 0;
  while (rgb[i])
  {
    j = 0;
    number = ft_atoi(rgb[i]);
    if (!(number >= 0 && number <= 255))
      return (1);
    while (rgb[i][j])
    {
      if (!ft_isdigit(rgb[i][j]))
        return (1);
      j++;
    }
    i++;
  }
  return (0);
}


int fill_color(char **color,unsigned int to_fill[3])
{
  int i;

  i = 0;
  while (i < 3)
  {
    if (!color[i])
      return (1);
    to_fill[i] = ft_atoi(color[i]);
    i++;
  }
  return (0);
}
