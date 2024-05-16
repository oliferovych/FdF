/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:59:52 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/16 17:17:14 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_head.h"

int	str_is_numerical(char *string)
{
	int	i;

	i = 0;
	if (string[0] == ' ')
		return (0);
	while ((string[i] >= '0' && string[i] <= '9') || (string[i] == '-'
			&& (string[i + 1] >= '0' && string[i + 1] <= '9'))
		|| (string[i] == '+' && (string[i + 1] >= '0' && string[i + 1] <= '9'))
		|| string[i] == ' ' || string[i] == ',')
	{
		if (string[i] == ',')
			while (string[i] != ' ' || string[i] != '\n')
				i++;
		i++;
	}
	if (i != ft_strlen(string) - 1)
		return (0);
	return (1);
}

void	ft_error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}

int	valid_name(char *name, int argc)
{
	if (argc != 2)
		return (ft_printf("Usage: ./FdF <filename>.fdf\n"), 0);
	if (!ft_strnstr(name, ".fdf", ft_strlen(name)))
		return (ft_printf("Usage: ./FdF <filename>.fdf\n"), 0);
	return (1);
}
