/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:23:26 by yaskour           #+#    #+#             */
/*   Updated: 2023/01/04 17:23:47 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlens(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substrs(char *s, unsigned int start, size_t len)
{
	char			*t;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlens(s))
		return (ft_strdups(""));
	if (len > ft_strlens(s))
		len = ft_strlens(s);
	i = 0;
	t = NULL;
	if (start == 0)
		t = malloc(ft_strlens(s) + 1);
	if (start != 0)
		t = malloc(len + 1);
	if (t == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		t[i] = (char)s[start];
		i++;
		start++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_frees(char **str)
{
	if (!*str)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_strdups(char *s1)
{
	char	*copy;
	int		len;
	int		i;

	i = 0;
	len = ft_strlens(s1);
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoins(char *s1, char *s2)
{
	char	*t;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdups(s2));
	j = 0;
	t = NULL;
	t = malloc(((ft_strlens(s1) + ft_strlens(s2)) + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	i = ft_strlens(s1);
	while (j < i)
	{
		t[j] = (char)s1[j];
		j++;
	}
	j = 0;
	while (s2[j])
		t[i++] = (char)s2[j++];
	t[i] = '\0';
	free(s1);
	return (t);
}
