/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:19:59 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/23 22:20:06 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_indice(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_next(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == '\0' || (str[i] == '\n' && str[i + 1] == '\0'))
		return (NULL);
	return (str + i + 1);
}

char	*ft_add(char *str, int fd)
{
	char	*buff;
	int		r;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (1)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
		{
			ft_frees(&buff);
			return (ft_frees(&str));
		}
		if (!r)
			break ;
		buff[r] = '\0';
		str = ft_strjoins(str, buff);
		if (ft_indice(str, '\n') != 0)
			break ;
	}
	ft_frees(&buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*ptr;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	if (ft_indice(str, '\n') == 0)
		str = ft_add(str, fd);
	if (ft_indice(str, '\n'))
		line = ft_substrs(str, 0, ft_indice(str, '\n'));
	else if (str)
		line = ft_strdups(str);
	else if (!str)
		line = NULL;
	ptr = str;
	if (ft_next(str, '\n'))
	{
		str = ft_strdups(ft_next(str, '\n'));
		ft_frees(&ptr);
	}
	else
		ft_frees(&str);
	return (line);
}
