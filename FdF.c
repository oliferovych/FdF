/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:09:03 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/14 18:15:19 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	leaks(void)
{
	system("leaks FdF");
}

static void	error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}

// static void	ft_hook(void *param)
// {
// 	const mlx_t	*mlx = param;

// 	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

int32_t	main(int argc, char **argv)
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (!openfile(argc, argv, &map))
		return (1);
	ft_allocate_map(&map);
	parse_file(argv[1], &map);
	mlx = mlx_init(WIDTH, HEIGHT, "you are stupid", true);
	if (!mlx)
		error();
	img = mlx_new_image(mlx, 1280, 720);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		error();
	int i;
	int j = map.height * 42;
	int z;
	while (j >= 0)
	{
		i = map.width * 42;
		while (i > 0)
		{
			z = i;
			i -= 42;
			while (z > i)
			{
				mlx_put_pixel(img, z + 200, j + 100, 0xFFFFFFFF);
				z--;
			}

		}
		j -= 42;
	}
	i = map.width * 42;
	while (i >= 0)
	{
		j = map.height * 42;
		while (j > 0)
		{
			z = j;
			j -= 42;
			while (z > j)
			{
				mlx_put_pixel(img, i + 200, z + 100, 0xFFFFFFFF);
				z--;
			}
		}
		i -= 42;
	}
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_the_map(&map);
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
