/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:21:38 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/16 20:00:07 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	parse_file(char *file, t_map *map)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**splitted;

	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		j = 0;
		splitted = ft_split(line, ' ');
		while (splitted[j])
		{
			map->flat[i][j] = atoi(splitted[j]);
			free(splitted[j]);
			j++;
		}
		free(line);
		free(splitted);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}
