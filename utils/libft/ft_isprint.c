/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:00:42 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/28 18:00:43 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint( int character )
{
	if (character >= ' ' && character <= 126)
		return (1);
	else
		return (0);
}
