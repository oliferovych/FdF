/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:10:03 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/16 18:42:34 by dolifero         ###   ########.fr       */
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

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	scale;
}				t_point;

typedef struct s_fdf
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_point		*points;
	char		*title;
	double		scale;
}				t_fdf;

int		openfile(int argc, char **argv, t_map *map);
void	ft_allocate_map(t_map *map);
void	parse_file(char *file, t_map *map);
void	free_allocations(t_fdf *fdf);

int		str_is_numerical(char *string);
void	ft_error(void);
int		valid_name(char *name, int argc);

void	overlay(t_fdf *fdf);
void	ft_3d_to_2d(t_map *map, t_point **points);
void	points_into_isometric(t_map *map, t_point **points, mlx_image_t *img);

void	ft_window_hook(void *param);
void	ft_rescale(void *param);
void	ft_hook_controls(t_fdf *fdf);

#endif
