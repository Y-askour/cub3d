/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:41:14 by yaskour           #+#    #+#             */
/*   Updated: 2021/11/05 13:46:16 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ptr;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (ptr);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
