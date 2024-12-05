/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:09:03 by dolifero          #+#    #+#             */
/*   Updated: 2024/12/05 22:51:35 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

static void	map(int argc, char **argv, t_map *map)
{
	if (!openfile(argc, argv, map))
		return (exit(1));
	ft_allocate_map(map);
	parse_file(argv[1], map);
	ft_printf("Map loaded\n");
}

void	ft_hook(t_fdf *fdf)
{
	mlx_loop_hook(fdf->mlx, &scale_hook, fdf);
	mlx_loop_hook(fdf->mlx, &move_hook, fdf);
	mlx_loop_hook(fdf->mlx, &translation_hook, fdf);
	mlx_loop_hook(fdf->mlx, ft_window_hook, fdf->mlx);
}

static void	draw_image(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	ft_copy_points(&fdf->map, fdf->points);
	points_into_isometric(fdf);
	background(fdf);
	draw_mesh(fdf);
}

static void malloc_iso_points(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->points = (t_point **)malloc(sizeof(t_point *) * fdf->map.height);
	while (i < fdf->map.height)
	{
		fdf->points[i] = (t_point *)malloc(sizeof(t_point) * fdf->map.width);
		i++;
	}
}

int32_t	main(int argc, char **argv)
{
	t_fdf	fdf;

	map(argc, argv, &fdf.map);
	fdf.title = ft_strjoin("FdF - ", argv[1]);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, fdf.title, true);
	if (!fdf.mlx)
		ft_error(&fdf);
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	fdf.bg_color = BG_1;
	fdf.standard_color = STANDARD_COLOR1;
	malloc_iso_points(&fdf);
	reset_img(&fdf);
	overlay(&fdf);
	ft_hook(&fdf);
	draw_image(&fdf);
	mlx_loop_hook(fdf.mlx, &draw_image, &fdf);
	if (!fdf.img || (mlx_image_to_window(fdf.mlx, fdf.img, 0, 0) < 0))
		ft_error(&fdf);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	free_allocations(&fdf);
	return (EXIT_SUCCESS);
}
