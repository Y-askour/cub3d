/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:37:05 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/24 16:55:30 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int check_east(t_all *data)
{
  char *str;
  char *trimed_str;
  int   len;

  len = 4;
  str = &data->parss.east[2];
  trimed_str = ft_strtrim(str," ");
  if (ft_strlen(data->parss.east) > 4)
    len = ft_strlen(data->parss.east);
  str = ft_strnstr(data->parss.east,".xpm",len);
  if (!str || (ft_strlen(trimed_str) <= 4) || (ft_strlen(str) > 4))
  {
    free(trimed_str);
    return (1);
  }
  data->valid.ea = trimed_str;
  if (open_file(data->valid.ea))
    return (1);
  return (0);
}

int check_west(t_all *data)
{
  char *str;
  char *trimed_str;
  int   len;

  len = 4;
  str = &data->parss.west[2];
  trimed_str = ft_strtrim(str," ");
  if (ft_strlen(data->parss.west) > 4)
    len = ft_strlen(data->parss.west);
  str = ft_strnstr(data->parss.west,".xpm",len);
  if (!str || (ft_strlen(trimed_str) <= 4) || (ft_strlen(str) > 4))
  {
    free(trimed_str);
    return (1);
  }
  data->valid.we = trimed_str;
  if (open_file(data->valid.we))
    return (1);
  return (0);
}

int check_south(t_all *data)
{
  char *str;
  char *trimed_str;
  int   len;

  len = 4;
  str = &data->parss.south[2];
  trimed_str = ft_strtrim(str," ");
  if (ft_strlen(data->parss.south) > 4)
    len = ft_strlen(data->parss.south);
  str = ft_strnstr(data->parss.south,".xpm",len);
  if (!str || (ft_strlen(trimed_str) <= 4) || (ft_strlen(str) > 4))
  {
    free(trimed_str);
    return (1);
  }
  data->valid.so = trimed_str;
  if (open_file(data->valid.so))
    return (1);
  return (0);
}

int check_north(t_all *data)
{
  char *str;
  char *trimed_str;
  int   len;

  len = 4;
  str = &data->parss.north[2];
  trimed_str = ft_strtrim(str," ");
  if (ft_strlen(data->parss.north) > 4)
    len = ft_strlen(data->parss.north);
  str = ft_strnstr(data->parss.north,".xpm",len);
  if (!str || (ft_strlen(trimed_str) <= 4) || (ft_strlen(str) > 4))
  {
    free(trimed_str);
    return (1);
  }
  data->valid.no = trimed_str;
  if (open_file(data->valid.no))
    return (1);
  return (0);
}

int check_textures(t_all *data)
{
  init_textures(data);
  if (check_south(data))
  {
    printf("check south texture\n");
    return (1);
  }
  if (check_north(data))
  {
    printf("check north texture\n");
    return (1);
  }
  if (check_west(data))
  {
    printf("check west texture\n");
    return (1);
  }
  if (check_east(data))
  {
    printf("check east texture\n");
    return (1);
  }
  return (0);
}
