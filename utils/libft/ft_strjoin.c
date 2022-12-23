/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:41:27 by yaskour           #+#    #+#             */
/*   Updated: 2021/11/14 17:01:47 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	int		len;
	char	*ptr;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	while (*str1)
		*ptr++ = *str1++;
	while (*str2)
		*ptr++ = *str2++;
	*ptr = '\0';
	return ((char *) ptr - len);
}
