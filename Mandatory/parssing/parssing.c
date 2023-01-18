/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:55:00 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/15 23:21:08 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	check_double_metadata(t_all *data)
{
	int	i;

	i = 0;
	while (data->parss.all[i])
	{
		if (!ft_strncmp(data->parss.all[i], "SO", 2))
			return (0);
		if (!ft_strncmp(data->parss.all[i], "WE", 2))
			return (0);
		if (!ft_strncmp(data->parss.all[i], "NO", 2))
			return (0);
		if (!ft_strncmp(data->parss.all[i], "EA", 2))
			return (0);
		if (!ft_strncmp(data->parss.all[i], "C", 1))
			return (0);
		if (!ft_strncmp(data->parss.all[i], "F", 1))
			return (0);
		i++;
	}
	return (1);
}

int	check_position(t_all *data)
{
	int	i;

	i = 0;
	while (data->parss.all[i])
	{
		if (ft_strlen(data->parss.all[i]))
			break ;
		i++;
	}
	data->parss.map_index = i;
	if (data->parss.map_index < data->parss.c_index)
		return (0);
	if (data->parss.map_index < data->parss.f_index)
		return (0);
	if (data->parss.map_index < data->parss.w_index)
		return (0);
	if (data->parss.map_index < data->parss.e_index)
		return (0);
	if (data->parss.map_index < data->parss.s_index)
		return (0);
	if (data->parss.map_index < data->parss.n_index)
		return (0);
	return (1);
}

int	parss_metadata(char *av, t_all *data)
{
	init_data(data);
	if (check_file_name(av))
		return (printf("check your name file\n"), 0);
	if (!read_file(av, data, 0))
	{
		printf("check if file is empty\n");
		return (0);
	}
	if (!get_metadata(data))
	{
		free_all(data);
		free_metadata(data);
		printf("metadata is missing\n");
		return (0);
	}
	if (!check_double_metadata(data))
	{
		free_all(data);
		free_metadata(data);
		printf("metadata is doubled");
		return (0);
	}
	return (1);
}

void	free_parssing(t_all *data)
{
	free(data->parss.floor);
	free(data->parss.ceiling);
	free(data->parss.east);
	free(data->parss.west);
	free(data->parss.north);
	free(data->parss.south);
}

int	parssing(char *av, t_all *data)
{
	if (!parss_metadata(av, data))
		return (0);
	if (!check_position(data))
	{
		free_all(data);
		free_metadata(data);
		printf("map is above a metadata");
		return (0);
	}
	get_map(data, 0, 0, 0);
	if (!data->parss.map)
	{
		free_parssing(data);
		printf("missing map\n");
		return (0);
	}
	return (1);
}
