/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:37:05 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/17 23:40:38 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

int	check_east(t_all *data, int i, int len)
{
	char	*str;
	char	*trimed_str;

	str = &data->parss.east[2];
	if (str[0] != ' ' && !(str[0] >= 9 && str[0] <= 13))
	{
		free(data->parss.east);
		return (1);
	}
	i = check_is_white_spaces(str);
	trimed_str = ft_strtrim(&str[i], " ");
	if (ft_strlen(data->parss.east) > 4)
		len = ft_strlen(data->parss.east);
	str = ft_strnstr(data->parss.east, ".xpm", len);
	free(data->parss.east);
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

int	check_west(t_all *data, int i, int len)
{
	char	*str;
	char	*trimed_str;

	str = &data->parss.west[2];
	if (str[0] != ' ' && !(str[0] >= 9 && str[0] <= 13))
	{
		free(data->parss.west);
		return (1);
	}
	i = check_is_white_spaces(str);
	trimed_str = ft_strtrim(&str[i], " ");
	if (ft_strlen(data->parss.west) > 4)
		len = ft_strlen(data->parss.west);
	str = ft_strnstr(data->parss.west, ".xpm", len);
	free(data->parss.west);
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

int	check_south(t_all *data, int i, int len)
{
	char	*str;
	char	*trimed_str;

	str = &data->parss.south[2];
	if (str[0] != ' ' && !(str[0] >= 9 && str[0] <= 13))
	{
		free(data->parss.south);
		return (1);
	}
	i = check_is_white_spaces(str);
	trimed_str = ft_strtrim(&str[i], " ");
	if (ft_strlen(data->parss.south) > 4)
		len = ft_strlen(data->parss.south);
	str = ft_strnstr(data->parss.south, ".xpm", len);
	free(data->parss.south);
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

int	check_north(t_all *data, int i, int len)
{
	char	*str;
	char	*trimed_str;

	str = &data->parss.north[2];
	if (str[0] != ' ' && !(str[0] >= 9 && str[0] <= 13))
	{
		free(data->parss.north);
		return (1);
	}
	i = check_is_white_spaces(str);
	trimed_str = ft_strtrim(&str[i], " ");
	if (ft_strlen(data->parss.north) > 4)
		len = ft_strlen(data->parss.north);
	str = ft_strnstr(data->parss.north, ".xpm", len);
	free(data->parss.north);
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

int	check_textures(t_all *data)
{
	init_textures(data);
	if (check_south(data, 0, 4))
	{
		free(data->parss.east);
		free(data->parss.north);
		free(data->parss.west);
		printf("check south texture\n");
		return (1);
	}
	if (check_north(data, 0, 4))
	{
		free(data->parss.east);
		free(data->parss.west);
		return (printf("check north texture\n"), 1);
	}
	if (check_west(data, 0, 4))
	{
		free(data->parss.east);
		return (printf("check west texture\n"), 1);
	}
	if (check_east(data, 0, 4))
		return (printf("check east texture\n"), 1);
	return (0);
}
