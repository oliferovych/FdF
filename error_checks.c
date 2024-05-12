/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:59:52 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/12 18:08:11 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

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


