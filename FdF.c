/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:09:03 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/14 17:38:47 by dolifero         ###   ########.fr       */
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
	int j = map.height * 30 + sin(25);
	while (j > 0)
	{
		i = map.width * 30 + cos(25);
		while (i > 0)
		{
			mlx_put_pixel(img, i + 325, j + 175, 0xFFFFFFFF);
			i -= 30;
		}
		j -= 30;
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
