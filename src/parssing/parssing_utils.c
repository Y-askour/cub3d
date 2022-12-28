/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:55:25 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/28 17:55:26 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int check_file(char *av)
{
  int fd;

  fd = open(av,O_RDONLY);
  if (fd < 0)
  {
    printf("file can't be opened\n");
    close(fd);
    exit(1);
  }
  return (fd);
}

int file_len(char *file)
{
  int i;
  char *str;
  int fd;

  i = 0;
  fd = check_file(file);
  if (fd == -3)
    return (1);
  str = get_next_line(fd);
  while(str)
  {
    free(str);
    str = get_next_line(fd);
    i++;
  }
  return (i);
}

void init_data(t_all *data)
{
  data->parss.all = NULL;
  data->parss.ceiling = NULL;
  data->parss.floor = NULL;
  data->parss.south = NULL;
  data->parss.north = NULL;
  data->parss.east = NULL;
  data->parss.west = NULL;
}

int check_file_name(char *av)
{
  char *ptr;
  unsigned int len;

  len = 3;
  ptr = ft_strchr(av,'.');
  if (!ptr)
    return (1);
  if (ft_strlen(ptr + 1)> len)
    len = ft_strlen(ptr + 1);
  if (ft_strncmp(ptr + 1,"cub",len))
    return (1);
  return (0);
}

int read_file(char *file,t_all *data)
{
  int fd;
  int len;
  char *line;
  char *trimed_line;
  int i;


  len = file_len(file);
  data->len = len;
  fd = check_file(file);
  i = 0;
  if (fd == -3 || len < 1)
    return (0);
  data->parss.all = malloc(sizeof(char *) * len + 1);
  line = get_next_line(fd);
  trimed_line = ft_strtrim(line,"\n");
  while (line)
  {
    data->parss.all[i] = trimed_line;
    free(line);
    line = get_next_line(fd);
    trimed_line = ft_strtrim(line,"\n");
    i++;
  }
  data->parss.all[i] = NULL;
  return (1);
}
