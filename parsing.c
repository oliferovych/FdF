/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:21:38 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/11 19:46:42 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	count_values(const char *s)
{
	int	values;
	int	i;

	i = 0;
	values = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		if (s[i] != ' ')
		{
			values++;
			while (s[i] && s[i] != ' '
				&& ((s[i] >= '0' && s[i] <= '9') || s[i] == '-'))
				i++;
		}
		else
			i++;
	}
	return (values);
}

int	openfile(int argc, char **argv, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	map->height = 0;
	map->width = 0;
	while (line != NULL)
	{
		if (!str_is_numerical(line) || argc != 2)
			return (free(line), ft_putstr_fd("File error", 2), 0);
		map->width += count_values(line);
		map->height++;
		if (map->width / map->height != count_values(line) && line != NULL)
			return (free(line), ft_putstr_fd("File error", 2), 0);
		free(line);
		line = get_next_line(fd);
	}
	map->width = map->width / map->height;
	free(line);
	ft_printf("width: %d\n", map->width);
	ft_printf("height: %d\n", map->height);
	close(fd);
	return (1);
}

