/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:47 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/19 19:54:40 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	overlay(t_fdf *fdf)
{
	mlx_put_string(fdf->mlx, "Arrow UP/DOWN:    Flatten", 5, 0);
	mlx_put_string(fdf->mlx, "+/-:         Zoom", 5, 20);
	mlx_put_string(fdf->mlx, "R:           Reset", 5, 40);
	mlx_put_string(fdf->mlx, "ESC:         Exit", 5, 80);
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
