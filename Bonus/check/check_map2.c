/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:39:42 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/17 23:40:29 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

unsigned int	big_len(t_all *data)
{
	unsigned int	len;
	int				i;

	i = 0;
	len = 0;
	while (data->valid.maps[i])
	{
		if (len < ft_strlen(data->valid.maps[i]))
			len = ft_strlen(data->valid.maps[i]);
		i++;
	}
	return (len);
}

void	init_map(t_all *data)
{
	int	i;
	int	end;

	end = endmap_index(data->parss.map);
	data->valid.maps = malloc(sizeof(char *) * (end + 2));
	if (!data->valid.maps)
		return ;
	i = 0;
	while (i <= end)
	{
		data->valid.maps[i] = ft_strdup(data->parss.map[i]);
		i++;
	}
	data->valid.map_len = i;
	data->valid.maps[i] = NULL;
	free_map(data);
}

int	check_characters(t_all *data)
{
	int	i;

	i = 0;
	while (data->valid.maps[i])
	{
		if (search(data->valid.maps[i], "10 NSEW"))
			return (1);
		i++;
	}
	return (0);
}

int	search(char *src, char *str)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (!ft_strchr(str, src[i]))
			return (1);
		i++;
	}
	return (0);
}

int	first_and_last_char(char **str, int map_len, int line_len)
{
	int	i;
	int	j;

	i = 1;
	while (i < map_len - 1)
	{
		j = 0;
		while (str[i][j] && str[i][j] == ' ')
			j++;
		if (str[i][j] != '1')
			return (1);
		j = line_len - 1;
		while (j > 0 && str[i][j] == ' ')
			j--;
		if (str[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}
