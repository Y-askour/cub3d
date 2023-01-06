/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:49 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/06 16:05:40 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	get_metadata(t_all *data)
{
	if (get_ceiling(data))
		return (0);
	if (get_floor(data))
		return (0);
	if (get_north(data))
		return (0);
	if (get_south(data))
		return (0);
	if (get_east(data))
		return (0);
	if (get_west(data))
		return (0);
	return (1);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 9 && str[i] <= 13) || (str[i] == ' ')))
			return (1);
		i++;
	}
	return (0);
}

void	get_map(t_all *data)
{
	int	i;
	int	len;
	int	temp;

	i = data->parss.map_index;
	len = 0;
	while (data->parss.all[i] && !is_empty(data->parss.all[i]))
		i++;
	if (!data->parss.all[i])
	{
		data->parss.map = NULL;
		free_all(data);
		return ;
	}
	temp = i;
	while (data->parss.all[i])
	{
		i++;
		len++;
	}
	data->parss.map = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (data->parss.all[temp])
	{
		data->parss.map[i] = ft_strdup(data->parss.all[temp]);
		temp++;
		i++;
	}
	data->parss.map[i] = NULL;
	free_all(data);
}
