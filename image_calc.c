/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:31:42 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/21 13:25:29 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

double	scale_calc(double scale)
{
	if(scale < 4)
		return (0.5);
	if(scale < 2)
		return (0.25);
	if(scale < 1)
		return (0);
	return (2);
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
	int		j;
	t_point	**points;

	points = fdf->points;
	i = -1;
	while (++i < fdf->map.height)
	{
		j = -1;
		while (++j < fdf->map.width)
		{
			points[i][j].z = (points[i][j].z / fdf->flatten) * fdf->scale;
			points[i][j].x *= fdf->scale;
			points[i][j].y *= fdf->scale;
			rotate_x(&points[i][j], fdf->rotation_x);
			rotate_y(&points[i][j], fdf->rotation_y);
			rotate_z(&points[i][j], fdf->rotation_z);
			if (fdf->iso == 1)
				project(&points[i][j]);
			points[i][j].x += WIDTH / 2 - (fdf->map.width * fdf->scale) / 2;
			points[i][j].y += HEIGHT / 2 - (fdf->map.height * fdf->scale) / 2;
			points[i][j].x += fdf->move_lr;
			points[i][j].y += fdf->move_du;
		}
	}
}
