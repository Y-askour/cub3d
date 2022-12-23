/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:45:01 by yaskour           #+#    #+#             */
/*   Updated: 2021/11/09 20:06:53 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_alloc(char *src, char c)
{
	size_t	len;
	char	*dest;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	len = 0;
	while (src[len] && src[len] != c)
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = 0;
	return (dest);
}

static size_t	count_words(char const *str, char c)
{
	size_t	words;

	words = 0;
	while (*str)
	{
		if (*str != c)
		{
			words++;
			while (*str && *str != c)
				str++;
			continue ;
		}
		str++;
	}
	return (words);
}

static int	ft_check_is_alloc(char **str, int j)
{
	if (str[j] == NULL)
	{
		while (j)
			free(str[--j]);
		free(str);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	words;
	size_t	w;

	w = 0;
	if (!s)
		return (NULL);
	words = count_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * words + 1);
	if (ptr == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			ptr[w] = ft_alloc((char *) s, c);
			if (!(ft_check_is_alloc(ptr, w++)))
				return (NULL);
			while (*(s + 1) && *(s + 1) != c)
				s++;
		}
		s++;
	}
	ptr[w] = NULL;
	return (ptr);
}
