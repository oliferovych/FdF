/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:36:11 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/21 01:14:50 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	rotate_z(t_point *point, double angle_z)
{
	int	tmp;

	tmp = point->x;
	point->x = tmp * cos(angle_z) - point->y * sin(angle_z);
	point->y = tmp * sin(angle_z) + point->y * cos(angle_z);
}

void	rotate_y(t_point *point, double angle_y)
{
	int	tmp;

	tmp = point->x;
	point->x = tmp * cos(angle_y) + point->z * sin(angle_y);
	point->z = point->z * cos(angle_y) - tmp * sin(angle_y);
}

void	rotate_x(t_point *point, double angle_x)
{
	int	tmp;

	tmp = point->y;
	point->y = tmp * cos(angle_x) - point->z * sin(angle_x);
	point->z = tmp * sin(angle_x) + point->z * cos(angle_x);
}

int	count_values(const char *s)
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
			while (s[i] && s[i] != ' ' && s[i] != '\n')
				i++;
		}
		else
			i++;
	}
	return (values);
}
