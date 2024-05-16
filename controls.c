/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:21:06 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/16 18:41:03 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	ft_window_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}

void	ft_rescale(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->scale += 2;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->scale -= 2;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_R))
		fdf ->scale = 6;
}

// void	ft_hook_controls(t_fdf *fdf)
// {
// 	mlx_key_hook(fdf->mlx, ft_rescale, fdf);
// 	mlx_loop_hook(fdf->mlx, ft_window_hook, &fdf);
// }
