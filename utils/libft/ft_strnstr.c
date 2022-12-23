/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:32:47 by yaskour           #+#    #+#             */
/*   Updated: 2021/11/12 03:54:45 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (*little)
	{
		if (*big++ != *little++ || len-- == 0)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(big) < ft_strlen(little))
		return (NULL);
	if (big == little || !ft_strlen(little))
		return ((char *)big);
	while (len > i && *(big + i))
	{
		if (*(big + i) == *(little) && ft_find(big + i, little, len - i))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
