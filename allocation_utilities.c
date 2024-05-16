/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:40:21 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/16 18:45:28 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

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
			{
				if (s[i] == ',')
					while (s[i] != ' ' || s[i] != '\n')
						i++;
				i++;
			}
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

	map->height = 0;
	map->width = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL && valid_name(argv[1], argc))
	{
		if (!str_is_numerical(line))
			return (free(line), ft_putstr_fd("File error\n", 2), 0);
		map->width += count_values(line);
		map->height++;
		if (map->width / map->height != count_values(line) && line != NULL)
			return (free(line), ft_putstr_fd("File error\n", 2), 0);
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

void	ft_allocate_map(t_map *map)
{
	int	i;

	i = 0;
	map->flat = (int **)malloc(sizeof(int *) * map->height);
	while (i != map->height)
	{
		map->flat[i] = (int *)malloc(sizeof(int) * map->width);
		i++;
	}
}

void	free_allocations(t_fdf *fdf)
{
	int	i;

	i = fdf->map.height;
	if (fdf->points != NULL)
		free(fdf->points);
	while (i > 0)
	{
		free(fdf->map.flat[i - 1]);
		i--;
	}
	free(fdf->map.flat);
	free(fdf->title);
}
