/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:59:24 by yaskour           #+#    #+#             */
/*   Updated: 2021/11/03 11:35:56 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset( void *pointer, int value, size_t count )
{
	size_t			i;
	unsigned char	*ptr;

	ptr = pointer;
	i = 0;
	while (i < count)
	{
		*ptr = (unsigned char ) value;
		ptr++;
		i++;
	}
	return (pointer);
}
