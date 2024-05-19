/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:10:03 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/19 21:07:53 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEAD_H
# define FDF_HEAD_H

# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# define WIDTH 1920
# define HEIGHT 1080
# define STANDARD_ZOOM 10
# define STANDARD_FLATTEN 1
# define STANDARD_ROT_Z 0
# define STANDARD_MOVE 0

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
}				t_point;

typedef struct s_fdf
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_point		*points;
	char		*title;
	double		flatten;
	double		scale;
	double		rotation_z;
	int			move_lr;
	int			move_du;
}				t_fdf;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}				t_bresenham;

// MAP INIT
void	ft_allocate_map(t_map *map);
void	parse_file(char *file, t_map *map);
void	free_allocations(t_fdf *fdf);

// ERROR CHECKS
int		openfile(int argc, char **argv, t_map *map);
int		str_is_numerical(char *string);
void	ft_error(t_fdf *fdf);
int		valid_name(char *name, int argc);

// IMAGE UTILITIES
void	overlay(t_fdf *fdf);
void	background(t_fdf *fdf);
void	ft_3d_to_2d(t_map *map, t_point **points);
void	points_into_isometric(t_fdf *fdf);
void	init_line_params(t_point p0, t_point p1, t_bresenham *params);
void	bresenham_line(mlx_image_t *img, t_point p0, t_point p1,
			t_bresenham params);

// DRAWING
void	draw_horizontal_lines(t_fdf *fdf);
void	draw_vertical_lines(t_fdf *fdf);
void	draw_mesh(void *param);

// HOOKS / CONTROLS
void	ft_window_hook(void *param);
void	scale_hook(void *param);
void	ft_hook(t_fdf *fdf);
void	reset_img(t_fdf *fdf);

// MATH UTILS
void	rotate_z(t_point *point, double angle_z);
void	rotate_y(t_point *point);
void	rotate_x(t_point *point);
int		count_values(const char *s);

#endif
