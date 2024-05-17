/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:21:06 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/17 17:07:23 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	ft_window_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
// 	if (mlx_is_key_down((* fdf).mlx, MLX_KEY_R))
// 		(*fdf).scale = 10;

void	scale_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		fdf->scale += 3;
		ft_printf("ZOOM IN\n");
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		fdf->scale -= 3;
		ft_printf("ZOOM OUT\n");
	}
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		fdf->scale = 20;
		ft_printf("RESET\n");
	}
}

// void	scroll_rescale(double xdelta, double ydelta, void *param)
// {
// 	t_fdf	*fdf;

// 	fdf = (t_fdf *)param;
// 	if (ydelta > 0)
// 		fdf->scale += 2;
// 	else if (ydelta < 0)
// 		fdf->scale -= 2;
// 	if (xdelta < 0)
// 		ft_printf("Sliiiide to the left!");
// 	else if (xdelta > 0)
// 		ft_printf("Sliiiide to the right!");
// }

void	ft_hook_controls(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx, scale_hook, &fdf);
	mlx_loop_hook(fdf->mlx, ft_window_hook, fdf->mlx);
}
