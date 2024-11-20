/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:47 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/20 04:35:56 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	overlay(t_fdf *fdf)
{
	mlx_put_string(fdf->mlx, "W/S:                   Flatten", 5, 0);
	mlx_put_string(fdf->mlx, "A/D:                   Rotate around Z-axis",
		5, 20);
	mlx_put_string(fdf->mlx, "+/-:                   Zoom", 5, 50);
	mlx_put_string(fdf->mlx, "Arrow keys:            Move", 5, 80);
	mlx_put_string(fdf->mlx, "Orthographic:          O", 5, 110);
	mlx_put_string(fdf->mlx, "Isometric              I", 5, 130);
	mlx_put_string(fdf->mlx, "R:                     Reset", 5, 160);
	mlx_put_string(fdf->mlx, "ESC:                   Exit", 5, 180);
}

void	background(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			mlx_put_pixel((*fdf).img, j, i, 0x6BACCFA5);
	}
}
