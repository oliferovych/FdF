/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:24:08 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/19 20:28:15 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	init_line_params(t_point p0, t_point p1, t_bresenham *params)
{
	params->dx = abs(p1.x - p0.x);
	params->dy = abs(p1.y - p0.y);
	if (p0.x < p1.x)
		params->sx = 1;
	else
		params->sx = -1;
	if (p0.y < p1.y)
		params->sy = 1;
	else
		params->sy = -1;
	params->err = params->dx - params->dy;
}

void	bresenham_line(mlx_image_t *img, t_point p0, t_point p1,
		t_bresenham params)
{
	int	e2;

	while (1)
	{
		if (p0.x > WIDTH || p0.y > HEIGHT || p1.x > WIDTH || p1.y > HEIGHT)
			break ;
		mlx_put_pixel(img, p0.x, p0.y, 0xFFFFFFFF);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		e2 = params.err * 2;
		if (e2 > -params.dy)
		{
			params.err -= params.dy;
			p0.x += params.sx;
		}
		if (e2 < params.dx)
		{
			params.err += params.dx;
			p0.y += params.sy;
		}
	}
}
