/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:31:42 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/05 23:13:58 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

double	scale_calc(double scale)
{
	if (scale < 4)
		return (0.5);
	if (scale < 2)
		return (0.25);
	if (scale < 1)
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

static void	translate(int *x, int *y, t_fdf *fdf)
{
	*x += (WIDTH / 2 - (fdf->map.width * fdf->scale) / 2) + fdf->move_lr;
	*y += (HEIGHT / 2 - (fdf->map.height * fdf->scale) / 2) + fdf->move_du;
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
			points[i][j].x *= fdf->scale;
			points[i][j].y *= fdf->scale;
			points[i][j].z *= fdf->scale;
			points[i][j].z /= fdf->flatten;
			points[i][j].x -= (fdf->map.width * fdf->scale) / 2;
			points[i][j].y -= (fdf->map.height * fdf->scale) / 2;
			rotate_z(&points[i][j], fdf->rotation_z);
			if (fdf->iso == 1)
				project(&points[i][j]);
			translate(&points[i][j].x, &points[i][j].y, fdf);
		}
	}
}
