/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:40:21 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/11 19:59:11 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_allocate_map(t_map *map)
{
	int	i;

	i = 0;
	map->flat = (int **)malloc(sizeof(int *) * map->height);
	while (i != map->height)
	{
		map->flat[i] = (int *)malloc(sizeof(int) * map->width);
		i++;
	}
}

void	free_the_map(t_map *map)
{
	while (map->height > 0)
	{
		free(map->flat[map->height - 1]);
		map->height--;
	}
	free(map->flat);
}
