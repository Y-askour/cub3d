/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:57:03 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/24 14:49:58 by yaskour          ###   ########.fr       */
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

void free_rgb(char **rgb)
{
  int i;

  i = 0;
  while (rgb[i])
    free(rgb[i++]);
  free(rgb);
}

void fill_color(char **color,unsigned int to_fill[3])
{
  int i;

  i = 0;
  while (i < 3)
  {
    to_fill[i] = ft_atoi(color[i]);
    i++;
  }
}

int check_floor(t_all *data)
{
  char **rgb;
  int   j;
  char *trimed_str;

  if (data->parss.floor[1] != ' ')
    return (0);
  trimed_str = ft_strtrim(&data->parss.floor[1]," ");
  j = cout_comma(trimed_str);
  if (j == 2)
  {
    rgb = ft_split(trimed_str,',');
    free(trimed_str);
    if (check_is_rgb(rgb))
    {
      free_rgb(rgb);
      return (0);
    }
    fill_color(rgb,data->valid.floor);
    free_rgb(rgb);
    return (1);
  }
  return (0);
}

int check_ceiling(t_all *data)
{
  char **rgb;
  int   j;
  char *trimed_str;

  if (data->parss.ceiling[1] != ' ')
    return (0);
  trimed_str = ft_strtrim(&data->parss.ceiling[1]," ");
  j = cout_comma(trimed_str);
  if (j == 2)
  {
    rgb = ft_split(trimed_str,',');
    free(trimed_str);
    if (check_is_rgb(rgb))
    {
      free_rgb(rgb);
      return (0);
    }
    fill_color(rgb,data->valid.ceiling);
    free_rgb(rgb);
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
  if (!check_floor(data))
  {
    printf("check floor\n");
    return (1);
  }
  return (0);
}
