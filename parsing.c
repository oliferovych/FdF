/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:21:38 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/21 13:02:56 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"
#include <stdlib.h>

char	*parse_color(char *str)
{
	char	*color;

	if (ft_strlen(str) != 8)
		return (str);
	color = ft_strjoin(str, "FF");
	free(str);
	return (color);
}

t_point	parse_point(char *str, int i, int j)
{
	t_point	point;
	char	**split;

	point.x = j + 1;
	point.y = i + 1;
	if (!ft_strchr(str, ','))
	{
		point.z = ft_atoi(str);
		point.color = 0xFFFFFFFF;
		return (point);
	}
	split = ft_split(str, ',');
	point.z = ft_atoi(split[0]);
	split[1] = parse_color(split[1]);
	point.color = hex_to_uint(split[1]);
	free(split[0]);
	free(split[1]);
	free(split);
	return (point);
}

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
		j = -1;
		splitted = ft_split(line, ' ');
		while (splitted[++j])
		{
			map->points[i][j] = parse_point(splitted[j], i, j);
			free(splitted[j]);
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(splitted);
	close(fd);
}
