/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:40:21 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/20 05:22:29 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	ft_allocate_map(t_map *map)
{
	int	i;

	i = 0;
	map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
	while (i != map->height)
	{
		map->points[i] = (t_point *)malloc(sizeof(t_point) * map->width);
		i++;
	}
}

void	free_points_copy(t_fdf *fdf)
{
	int	i;

	i = fdf->map.height;
	while (i > 0)
	{
		free(fdf->points[i - 1]);
		i--;
	}
	free(fdf->points);
}

void	free_allocations(t_fdf *fdf)
{
	int	i;

	i = fdf->map.height;
	while (i > 0)
	{
		free(fdf->map.points[i - 1]);
		i--;
	}
	free(fdf->map.points);
	free(fdf->title);
}

t_point **ft_copy_points(t_map *map)
{
	t_point	**points;
	int		i;
	int		j;

	i = 0;
	points = (t_point **)malloc(sizeof(t_point *) * map->height);
	while (i < map->height)
	{
		j = 0;
		points[i] = (t_point *)malloc(sizeof(t_point) * map->width);
		while (j < map->width)
		{
			points[i][j] = map->points[i][j];
			j++;
		}
		i++;
	}
	return (points);
}


