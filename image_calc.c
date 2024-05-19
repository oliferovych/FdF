/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:31:42 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/19 21:17:23 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	ft_3d_to_2d(t_map *map, t_point **points)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	*points = malloc(sizeof(t_point) * (map->width * map->height));
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			(*points)[k].x = j + 1;
			(*points)[k].y = i + 1;
			(*points)[k].z = map->flat[i][j];
			j++;
			k++;
		}
		i++;
	}
}

void	project(t_point *point)
{
	double	tmp_x;
	double	tmp_y;
	double	angle;

	angle = 0.523599;
	tmp_x = point->x * cos(angle) - point->y * cos(angle);
	tmp_y = point->x * sin(angle) + point->y * sin(angle);
	point->x = (int)tmp_x;
	point->y = (int)tmp_y - point->z;
}

void	points_into_isometric(t_fdf	*fdf)
{
	int		i;
	t_point	*points;

	points = fdf->points;
	i = 0;
	background(fdf);
	while (i < fdf->map.height * fdf->map.width)
	{
		points[i].z /= fdf->flatten;
		points[i].x *= fdf->scale;
		points[i].y *= fdf->scale;
		points[i].z *= fdf->scale;
		rotate_x(&points[i]);
		rotate_y(&points[i]);
		rotate_z(&points[i], fdf->rotation_z);
		project(&points[i]);
		points[i].x += WIDTH / 2 - (fdf->map.width * fdf->scale) / 2;
		points[i].y += HEIGHT / 2 - (fdf->map.height * fdf->scale) / 2;
		points[i].x += fdf->move_lr;
		points[i].y += fdf->move_du;
		i++;
	}
}
