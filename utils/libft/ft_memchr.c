/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:36:44 by yaskour           #+#    #+#             */
/*   Updated: 2021/11/12 03:56:22 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	find;

	i = 0;
	str = (unsigned char *) s;
	find = (unsigned char) c;
	while (i++ < n)
	{
		if (*str == find)
			return (str);
		str++;
	}
	return (NULL);
}
