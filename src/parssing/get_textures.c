/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:07:42 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/04 17:25:09 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	get_west(t_all *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->parss.all[i])
	{
		if (!ft_strncmp(data->parss.all[i], "WE", 2))
		{
			data->parss.west = ft_strdup(data->parss.all[i]);
			temp = data->parss.all[i];
			data->parss.w_index = i;
			data->parss.all[i] = ft_strdup("");
			free(temp);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_east(t_all *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->parss.all[i])
	{
		if (!ft_strncmp(data->parss.all[i], "EA", 2))
		{
			data->parss.east = ft_strdup(data->parss.all[i]);
			temp = data->parss.all[i];
			data->parss.e_index = i;
			data->parss.all[i] = ft_strdup("");
			free(temp);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_north(t_all *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->parss.all[i])
	{
		if (!ft_strncmp(data->parss.all[i], "NO", 2))
		{
			data->parss.north = ft_strdup(data->parss.all[i]);
			temp = data->parss.all[i];
			data->parss.n_index = i;
			data->parss.all[i] = ft_strdup("");
			free(temp);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_south(t_all *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->parss.all[i])
	{
		if (!ft_strncmp(data->parss.all[i], "SO", 2))
		{
			data->parss.south = ft_strdup(data->parss.all[i]);
			temp = data->parss.all[i];
			data->parss.s_index = i;
			data->parss.all[i] = ft_strdup("");
			free(temp);
			return (0);
		}
		i++;
	}
	return (1);
}
