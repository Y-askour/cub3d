/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:26:38 by yaskour           #+#    #+#             */
/*   Updated: 2021/11/12 03:55:41 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((*s1 || *s2) && *s1 == *s2 && i < n -1)
	{
		s1++;
		s2++;
		i++;
	}
	if (n)
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
	return (0);
}
