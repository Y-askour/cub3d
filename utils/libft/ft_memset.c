/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:04:41 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/28 18:04:42 by yaskour          ###   ########.fr       */
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
