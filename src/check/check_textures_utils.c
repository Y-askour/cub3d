/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:54:15 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/24 16:56:47 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int open_file(char *str)
{
  int fd;

  fd = open(str,O_RDONLY);
  if (fd < 0)
    return (1);
  return (0);
}

void  init_textures(t_all *data)
{
  data->valid.ea = NULL;
  data->valid.we = NULL;
  data->valid.so = NULL;
  data->valid.no = NULL;
}