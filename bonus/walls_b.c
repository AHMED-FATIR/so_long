/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:50:21 by afatir            #+#    #+#             */
/*   Updated: 2023/02/07 09:05:08 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	valid_s_b(char c)
{
	if (c == '0' || c == '1' || c == 'P' \
	|| c == 'C' || c == 'E' || c == 'A')
		return (1);
	return (0);
}

int	side_w_b(char **str, int i, int ln)
{
	int		j;

	j = 0;
	if (str[i][j] == '1')
	{
		while (str[i][j] != '\n' && str[i][j])
		{
			if (!valid_s_b(str[i][j]))
				return (0);
			j++;
		}
		if (j == ln && str[i][j - 1] == '1')
			return (1);
	}
	return (0);
}

int	last_w_b(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	first_w_b(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
