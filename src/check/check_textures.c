/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:37:05 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/06 16:04:32 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/include.h"

int	check_is_white_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			return (i);
		i++;
	}
	return (i);
}

int	check_east(t_all *data)
{
	char	*str;
	char	*trimed_str;
	int		i;
	int		len;

	len = 4;
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

int	check_west(t_all *data)
{
	char	*str;
	char	*trimed_str;
	int		i;
	int		len;

	len = 4;
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

int	check_south(t_all *data)
{
	char	*str;
	char	*trimed_str;
	int		i;
	int		len;

	len = 4;
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

int	check_north(t_all *data)
{
	char	*str;
	char	*trimed_str;
	int		len;
	int		i;

	len = 4;
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
	if (check_south(data))
	{
		free(data->parss.east);
		free(data->parss.north);
		free(data->parss.west);
		printf("check south texture\n");
		return (1);
	}
	if (check_north(data))
	{
		free(data->parss.east);
		free(data->parss.west);
		printf("check north texture\n");
		return (1);
	}
	if (check_west(data))
	{
		free(data->parss.east);
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
