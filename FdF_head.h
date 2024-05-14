/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:10:03 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/14 16:39:26 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
#define WIDTH 1280
#define HEIGHT 720

typedef struct s_map
{
	int	width;
	int	height;
	int	**flat;
}				t_map;

int		openfile(int argc, char **argv, t_map *map);
void	ft_allocate_map(t_map *map);
void	parse_file(char *file, t_map *map);
void	free_the_map(t_map *map);

int		str_is_numerical(char *string);

void	ft_hook(void *param);

#endif
