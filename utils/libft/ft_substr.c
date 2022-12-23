/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:38:15 by yaskour           #+#    #+#             */
/*   Updated: 2021/11/15 18:10:11 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) + 1)
		len = ft_strlen(s);
	ptr = malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (s[start] && len--)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
