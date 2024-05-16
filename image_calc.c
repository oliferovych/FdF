/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:31:42 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/16 18:34:23 by dolifero         ###   ########.fr       */
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
	ft_printf("o\n");
	*points = malloc(sizeof(t_point) * (map->width * map->height));
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			(*points)[k].x = j + 1;
			(*points)[k].y = i + 1;
			(*points)[k].z = map->flat[i][j];
			ft_printf("x: %d\ny: %d\nz: %d\n\n", (*points)[k].x, (*points)[k].y,
				(*points)[k].z);
			j++;
			k++;
		}
		i++;
	}
	ft_printf("total points: %d\n", k);
	ft_printf("estimated points: %d\n", map->height * map->width);
}

void	points_into_isometric(t_map *map, t_point **points, mlx_image_t *img)
{
	int		i;
	int		tmp;
	double	angle;
	double	sc;

	sc = 3;
	angle = 0.523599;
	i = 0;
	while (i < map->height * map->width)
	{
		tmp = (*points)[i].x;
		(*points)[i].x = (tmp - (*points)[i].y) * cos(angle);
		(*points)[i].y = (tmp + (*points)[i].y) * sin(angle) - (*points)[i].z;
		(*points)[i].x *= sc;
		(*points)[i].y *= sc;
		(*points)[i].x += WIDTH / 2;
		(*points)[i].y += HEIGHT / 2;
		mlx_put_pixel(img, (*points)[i].x, (*points)[i].y, 0xFFFFFFFF);
		i++;
	}
}
