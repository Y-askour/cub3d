/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:24:25 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/28 21:51:34 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

unsigned int big_len(t_all *data)
{
  unsigned int len;
  int i;


  i = 0;
  len = 0;
  while (data->parss.map[i])
  {
    if (len < ft_strlen(data->parss.map[i]))
      len = ft_strlen(data->parss.map[i]);
    i++;
  }
  return (len);
}

void str_space(char **dest,char *original,unsigned int b_len)
{
  char *to_fill;
  int len;
  int diff;
  len = ft_strlen(original);
  diff = b_len - len;
  to_fill = malloc(sizeof(char)  * (len  + diff + 1));
  int i;

  i = 0;

  while(original[i])
  {
    to_fill[i] = original[i];
    i++;
  }
  while(diff)
  {
    to_fill[i] = ' '; 
    i++;
    diff--;
  }
  to_fill[i] = '\0';
  *dest = to_fill;
}

void add_space(t_all *data)
{
  char **map;
  int i;
  int b_len;

  
  b_len = big_len(data);
  i = 0;
  while(data->parss.map[i])
    i++;
  map = malloc(sizeof(char *) * (i + 1));
  if (!map)
    return ;
  i = 0;
  while (data->parss.map[i])
  {
    str_space(&map[i],data->parss.map[i],b_len);
    free(data->parss.map[i]);
    i++;
  }
  map[i] = NULL;
  free(data->parss.map);
  data->parss.map = map;
}


int endmap_index(char **str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  i--;
  while (str[i])
  {
    if (ft_strlen(str[i]) && is_empty(str[i]))
      break;
    i--;
  }
  return (i);
}

void init_map(t_all *data)
{
  int i;

  int end;
  end = endmap_index(data->parss.map);
  data->valid.maps = malloc(sizeof(char *) * (end + 2));

  i = 0;
  while (i <= end)
  {
    data->valid.maps[i] = ft_strdup(data->parss.map[i]);
    i++;
  }
  data->valid.maps[i] = NULL;
  free_map(data);
}

int check_map(t_all *data)
{
  int i;

  init_map(data);
  i = 0;
  while (data->valid.maps[i])
  {
    free(data->valid.maps[i++]);
  }
  free(data->valid.maps);
  return (0);
}
