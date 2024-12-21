/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:36:11 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/21 13:05:06 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

void	rotate_z(t_point *point, double angle_z)
{
	double	x;
	double	y;

	x = (double)point->x;
	y = (double)point->y;
	point->x = (int)round(x * cos(angle_z) - y * sin(angle_z));
	point->y = (int)round(x * sin(angle_z) + y * cos(angle_z));
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

unsigned int	hex_to_uint(const char *hex_str)
{
	unsigned int	result;
	char			c;
	int				value;

	result = 0;
	if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X'))
		hex_str += 2;
	while (*hex_str)
	{
		c = *hex_str++;
		if (c >= '0' && c <= '9')
			value = c - '0';
		else if (c >= 'a' && c <= 'f')
			value = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			value = c - 'A' + 10;
		else
			return (0);
		result = (result << 4) | value;
	}
	return (result);
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
