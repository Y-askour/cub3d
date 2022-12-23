/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:57:03 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/23 22:44:56 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int cout_comma(char *str)
{
  int i;
  int j;

  i = 2;
  j = 0;
  while (str[i])
  {
    if (str[i] == ',')
      j++;
    i++;
  }
  return (j);
}


int check_ceiling(t_all *data)
{
  char **rgb;
  int   j;

  char *trimed_str;

  trimed_str = ft_strtrim(&data->parss.ceiling[1],"   ");
  printf("%s\n",trimed_str);
  j = cout_comma(trimed_str);
  if (j == 2)
  {
    rgb = ft_split(trimed_str,',');
    j = 0;
    while (rgb[j])
      printf("%s\n",rgb[j++]);
    return (1);
  }
  return (0);
}

int check_colors(t_all *data)
{
  if (!check_ceiling(data))
  {
    printf("check ceiling\n");
    return (1);
  }
  return (0);
}
