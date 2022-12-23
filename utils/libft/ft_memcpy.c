/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:25:19 by yaskour           #+#    #+#             */
/*   Updated: 2021/11/12 00:27:23 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destc;
	unsigned char		*srcc;

	srcc = (unsigned char *) src;
	destc = (unsigned char *) dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i++ < n)
		*destc++ = *srcc++;
	return (dest);
}
