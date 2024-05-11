/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:09:03 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/11 20:00:47 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	leaks(void)
{
	system("leaks FdF");
}

int	main(int argc, char **argv)
{
	t_map	map;

	atexit(leaks);
	if (!openfile(argc, argv, &map))
		return (1);
	ft_allocate_map(&map);
	free_the_map(&map);
	return (0);
}
