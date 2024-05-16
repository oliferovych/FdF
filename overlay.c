/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:47 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/16 17:13:35 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	overlay(t_fdf *fdf)
{
	mlx_put_string(fdf->mlx, "Left Click:   Pan", 5, 0
		);
	mlx_put_string(fdf->mlx, "Right Click:  Rotate x/y", 5, 20
		);
	mlx_put_string(fdf->mlx, "Middle Click: Rotate z", 5, 40);
	mlx_put_string(fdf->mlx, "R:            Reset", 5, 80);
	mlx_put_string(fdf->mlx, "-/+:          Flatten", 5, 100);
}
