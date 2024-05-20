/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:24:08 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/20 14:29:39 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	init_line_params(t_point src, t_point dest, t_bresenham *params)
{
	params->dx = abs(dest.x - src.x);
	params->dy = abs(dest.y - src.y);
	if (src.x < dest.x)
		params->sx = 1;
	else
		params->sx = -1;
	if (src.y < dest.y)
		params->sy = 1;
	else
		params->sy = -1;
	params->err = params->dx - params->dy;
}

void	bresenham_line(mlx_image_t *img, t_point src, t_point dest,
		t_bresenham params)
{
	int	e2;

	while (1)
	{
		if (src.x >= WIDTH || src.y >= HEIGHT || dest.x >= WIDTH
			|| dest.y >= HEIGHT || src.x < 0 || src.y < 0 || dest.x < 0
			|| dest.y < 0)
			break ;
		mlx_put_pixel(img, src.x, src.y, 0xFFFFFFFF);
		if (src.x == dest.x && src.y == dest.y)
			break ;
		e2 = params.err * 2;
		if (e2 > -params.dy)
		{
			params.err -= params.dy;
			src.x += params.sx;
		}
		if (e2 < params.dx)
		{
			params.err += params.dx;
			src.y += params.sy;
		}
	}
}
