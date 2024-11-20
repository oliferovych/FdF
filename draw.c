/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:48:34 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/20 06:12:08 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	draw_line(mlx_image_t *img, t_point p0, t_point p1, t_map *map)
{
	t_bresenham	params;

	p0.x += map->width / 2;
	p0.y += map->height / 2;
	p1.x += map->width / 2;
	p1.y += map->height / 2;
	init_line_params(p0, p1, &params);
	bresenham_line(img, p0, p1, params);
}

void	draw_horizontal_lines(t_fdf *fdf)
{
	int		i;
	int		j;
	t_point	**points;

	points = fdf->points;
	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width - 1)
		{
			draw_line(fdf->img, points[i][j], points[i][j + 1], &fdf->map);
			j++;
		}
		i++;
	}
}

void	draw_vertical_lines(t_fdf *fdf)
{
	int		i;
	int		j;
	t_point	**points;

	points = fdf->points;
	i = 0;
	while (i < fdf->map.height - 1)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			draw_line(fdf->img, points[i][j], points[i + 1][j], &fdf->map);
			j++;
		}
		i++;
	}
}

void	draw_mesh(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	draw_horizontal_lines(fdf);
	draw_vertical_lines(fdf);
}
