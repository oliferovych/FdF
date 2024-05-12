/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:09:03 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/12 18:34:54 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	leaks(void)
{
	system("leaks FdF");
}

// static void error(void)
// {
// 	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
// 	exit(EXIT_FAILURE);
// }

int	main(int argc, char **argv)
{
	t_map	map;

	if (!openfile(argc, argv, &map))
		return (1);
	ft_allocate_map(&map);
	parse_file(argv[1], &map);
	// mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	// if (!mlx)
	// 	error();
	for(int i = 0; i < map.height; i++)
	{
		for(int j = 0; j < map.width; j++)
		{
			ft_printf("%d ", map.flat[i][j]);
			if (map.flat[i][j] < 10)
				write(1, " ", 1);
		}
		ft_printf("\n");
	}
	free_the_map(&map);
	return (0);
}

