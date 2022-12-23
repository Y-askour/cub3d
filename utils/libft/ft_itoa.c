/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:36:20 by yaskour           #+#    #+#             */
/*   Updated: 2021/11/16 18:13:01 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_rev(char *s)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = ft_strlen(s) - 1;
	while (i < len)
	{
		temp = s[i];
		s[i++] = s[len];
		s[len--] = temp;
	}
}

static int	ft_num_len(int n)
{
	int	i;

	i = 0;
	if (!n)
		i = 1;
	else
	{
		if (n < 0)
		{
			i = 1;
			n *= -1;
		}
		while (n)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

static void	ft_convert(int n, char *str, int len)
{
	int	i;

	i = 0;
	if (!n)
		str[0] = '0';
	if (n < 0)
	{
		str[len - 1] = '-';
		n *= -1;
	}
	while (n)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	str[len] = 0;
	ft_rev(str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_num_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		ft_strlcpy(str, "-2147483648", 12);
	else
	{
		ft_convert(n, str, len);
	}
	return (str);
}
