/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:59:52 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/21 01:55:46 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	str_is_numerical(char *string)
{
	int	i;

	i = 0;
	while (string[i] && string[i] != '\n')
	{
		if (ft_isdigit(string[i])
			|| (string[i] == '-' && ft_isdigit(string[i + 1]))
			|| (string[i] == '+' && ft_isdigit(string[i + 1]))
			|| string[i] == ' '
			|| string[i] == ',')
		{
			if (string[i] == ',')
			{
				i++;
				while (string[i] && string[i] != ' ' && string[i] != '\n')
					i++;
			}
			else
				i++;
		}
		else
			return (0);
	}
	return (1);
}

void	ft_error(t_fdf *fdf)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	free_allocations(fdf);
	exit(EXIT_FAILURE);
}

int	valid_name(char *name, int argc)
{
	if (argc != 2)
		return (ft_printf("Usage: ./FdF <filename>.fdf\n"), exit(1), 0);
	if (!ft_strnstr(name, ".fdf", ft_strlen(name)))
		return (ft_printf("Usage: ./FdF <filename>.fdf\n"), exit(1), 0);
	return (1);
}

int	openfile(int argc, char **argv, t_map *map)
{
	char	*line;
	int		fd;

	map->height = 0;
	map->width = 0;
	if (valid_name(argv[1], argc))
	{
		fd = open(argv[1], O_RDONLY);
		line = get_next_line(fd);
		while (line != NULL && valid_name(argv[1], argc))
		{
			if (!str_is_numerical(line))
				return (free(line), ft_putstr_fd("File error\n", 2), 0);
			map->width += count_values(line);
			map->height++;
			free(line);
			line = get_next_line(fd);
		}
		map->width = map->width / map->height;
		free(line);
		close(fd);
	}
	ft_printf("%i, %i\n", map->width, map->height);
	return (1);
}
