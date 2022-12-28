/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:58:22 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/28 18:09:39 by yaskour          ###   ########.fr       */
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
