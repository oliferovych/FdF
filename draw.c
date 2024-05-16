/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:48:34 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/16 18:12:52 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

static void	slope_less_than_1(t_point *a, t_point *b, mlx_image_t *img)
{
	int	p;
	int	i;
	int	dx;
	int	dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	i = 0;
	p = 2 * dy - dx;
	mlx_put_pixel(img, a->x, a->y, 0xFFFFFFFF);
	while (i < dx)
	{
		a->x += 1;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			a->y += 1;
			p = p + 2 * dy - 2 * dx;
		}
		mlx_put_pixel(img, a->x, a->y, 0xFFFFFFFF);
		i++;
	}
}

static void	slope_bigger_than_1(t_point *a, t_point *b, mlx_image_t *img)
{
	int	p;
	int	i;
	int	dx;
	int	dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	i = 0;
	p = 2 * dx - dy;
	mlx_put_pixel(img, a->x, a->y, 0xFFFFFFFF);
	while (i < dy)
	{
		a->y += 1;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			a->x += 1;
			p = p + 2 * dx - 2 * dy;
		}
		mlx_put_pixel(img, a->x, a->y, 0xFFFFFFFF);
		i++;
	}
}

static void	draw_lines(mlx_image_t *img, t_point *src, t_point *dst)
{
	int	dx;
	int	dy;

	dx = dst->x - src->x;
	dy = dst->y - dst->y;
	if (abs(dx) > abs(dy))
		slope_less_than_1(src, dst, img);
	else
		slope_bigger_than_1(src, dst, img);
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (x < fdf->map.width)
	{
		y = 0;
		while (y < fdf->map.height)
		{
			i++;
			draw_lines(fdf->img, &fdf->points[i - 1], &fdf->points[i]);
			y++;
		}
		x++;
	}
}
