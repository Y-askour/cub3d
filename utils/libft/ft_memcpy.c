/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:10:19 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/04 17:24:03 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destc;
	unsigned char	*srcc;

	srcc = (unsigned char *)src;
	destc = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i++ < n)
		*destc++ = *srcc++;
	return (dest);
}
