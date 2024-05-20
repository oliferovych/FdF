/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:40:21 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/20 13:38:11 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

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

void	free_allocations(t_fdf *fdf)
{
	int	i;

	i = fdf->map.height;
	// if (fdf->points != NULL)
	// 	free(fdf->points);
	while (i > 0)
	{
		free(fdf->map.flat[i - 1]);
		i--;
	}
	free(fdf->map.flat);
	free(fdf->title);
}
