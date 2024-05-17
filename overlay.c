/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:47 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/17 17:04:39 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	overlay(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			mlx_put_pixel((*fdf).img, j, i, 0x000000FF);
	}
	// 0x6BACCFA5
	// ft_memset((*fdf).img->pixels, 10, (*fdf).img->width * (*fdf).img->height * sizeof(int32_t));
	mlx_put_string(fdf->mlx, "Arrow UP:    Zoom in", 5, 0);
	mlx_put_string(fdf->mlx, "Arrow DOWN:  Zoom out", 5, 20);
	mlx_put_string(fdf->mlx, "R:           Reset", 5, 40);
	mlx_put_string(fdf->mlx, "ESC:         Exit", 5, 80);
	// mlx_put_string(fdf->mlx, "-/+:          Flatten", 5, 100);
}
