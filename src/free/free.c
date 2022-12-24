/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:11:15 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/24 15:31:07 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/include.h"

void free_all(t_all *data)
{
  int i;

  i = 0;
  while(data->parss.all[i])
    free(data->parss.all[i++]);
  free(data->parss.all);
}

void free_metadata(t_all *data)
{
  free(data->parss.east);
  free(data->parss.west);
  free(data->parss.north);
  free(data->parss.south);
  free(data->parss.ceiling);
  free(data->parss.floor);
}

void free_rgb(char **rgb)
{
  int i;

  i = 0;
  while (rgb[i])
    free(rgb[i++]);
  free(rgb);
}
