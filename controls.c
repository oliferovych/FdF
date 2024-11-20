/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:21:06 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/20 03:57:19 by dolifero         ###   ########.fr       */
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

void	reset_img(t_fdf *fdf)
{
	fdf->scale = STANDARD_ZOOM;
	fdf->flatten = STANDARD_FLATTEN;
	fdf->move_lr = STANDARD_MOVE;
	fdf->move_du = STANDARD_MOVE;
	fdf->rotation_x = STANDARD_ROT;
	fdf->rotation_y = STANDARD_ROT;
	fdf->rotation_z = STANDARD_ROT;
	fdf->iso = 1;
}

void	scale_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
		fdf->scale += 3;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
		fdf->scale -= 3;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->flatten -= 0.1;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->flatten += 0.1;
	if (fdf->flatten > 10)
		fdf->flatten = 10;
	if (fdf->flatten < 0)
		fdf->flatten = 0;
	if (fdf->iso == 1)
	{
		if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
			fdf->rotation_z += 0.1;
		else if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
			fdf->rotation_z -= 0.1;
	}
}

void	move_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->move_lr -= 10;
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_RIGHT))
		fdf->move_lr += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->move_du -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->move_du += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_R))
		reset_img(fdf);
}

void	translation_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_O))
	{
		reset_img(fdf);
		fdf->ort = 1;
		fdf->iso = 0;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
	{
		reset_img(fdf);
		fdf->ort = 0;
		fdf->iso = 1;
	}
}
