/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:23:39 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/01/17 23:46:54 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include_bonus.h"

void	free_all(t_all *data)
{
	int	i;

	i = 0;
	while (data->parss.all[i])
		free(data->parss.all[i++]);
	free(data->parss.all);
}
