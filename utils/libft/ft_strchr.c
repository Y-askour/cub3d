/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:11:13 by yaskour           #+#    #+#             */
/*   Updated: 2021/11/06 16:01:53 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	size;

	i = 0;
	size = (int)ft_strlen(s) + 1;
	while (i < size)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		i++;
	}
	return (NULL);
}
