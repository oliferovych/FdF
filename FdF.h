/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:10:03 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/11 19:59:53 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include <math.h>

typedef struct s_map
{
	int	width;
	int	height;
	int	**flat;
}				t_map;


int		openfile(int argc, char **argv, t_map *map);
void	ft_allocate_map(t_map *map);
void	free_the_map(t_map *map);

int		str_is_numerical(char *string);


#endif
