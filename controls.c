/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:21:06 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/14 16:41:33 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	ft_hook(void *param)
{
	mlx_image_t	*img;

	img = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
}
