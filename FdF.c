/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:09:03 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/16 18:44:26 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	leaks(void)
{
	system("leaks FdF");
}

int32_t	main(int argc, char **argv)
{
	t_fdf	fdf;

	atexit(leaks);
	if (!openfile(argc, argv, &fdf.map))
		return (1);
	ft_allocate_map(&fdf.map);
	parse_file(argv[1], &fdf.map);
	fdf.title = ft_strjoin("FdF - ", argv[1]);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, fdf.title, true);
	ft_3d_to_2d(&fdf.map, &fdf.points);
	if (!fdf.mlx)
		ft_error();
	fdf.img = mlx_new_image(fdf.mlx, 1280, 720);
	if (!fdf.img || (mlx_image_to_window(fdf.mlx, fdf.img, 0, 0) < 0))
		ft_error();
	overlay(&fdf);
	// ft_hook_controls(&fdf);
	points_into_isometric(&fdf.map, &fdf.points, fdf.img);
	ft_printf("%d\n", fdf.points[1].x);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	free_allocations(&fdf);
	return (EXIT_SUCCESS);
}

	// for (int i = 0; i < map.height; i++)
	// {
	// 	for (int j = 0; j < map.width; j++)
	// 	{
	// 		ft_printf("%d ", map.flat[i][j]);
	// 		if (map.flat[i][j] < 10)
	// 			write(1, " ", 1);
	// 	}
	// 	ft_printf("\n");
	// }
