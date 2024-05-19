/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:36:11 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/19 19:58:05 by dolifero         ###   ########.fr       */
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

void	rotate_y(t_point *point)
{
	int	tmp;

	tmp = point->x;
	point->x = tmp * cos(0) + point->z * sin(0);
	point->z = point->z * cos(0) - tmp * sin(0);
}

void	rotate_x(t_point *point)
{
	int	tmp;

	tmp = point->y;
	point->y = tmp * cos(0) - point->z * sin(0);
	point->z = tmp * sin(0) + point->z * cos(0);
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
