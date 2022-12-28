/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:08:23 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/28 18:08:25 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_check(char s, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_check(s1[i], (char *)set))
		i++;
	if (i == len)
		return (ft_strdup(""));
	while (ft_check(s1[len - 1], (char *)set))
		len--;
	ptr = malloc((len - i) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[i], len - i + 1);
	return (ptr);
}
