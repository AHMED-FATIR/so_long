/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:46:16 by afatir            #+#    #+#             */
/*   Updated: 2023/02/07 11:57:06 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	valid_path_b(t_data *data)
{
	char	**p;

	p = f_valid_path_b(data);
	s_valid_path_b(p);
	if (!end_path_b(p))
		return (ft_free_all(p), 0);
	return (ft_free_all(p), 1);
}

char	**f_valid_path_b(t_data *data)
{
	t_var	v;

	v.j = 0;
	v.str = ft_calloc((data->g_y + 1), sizeof(char *));
	if (!v.str)
		ft_free_b(data, 2);
	while (data->map[v.j])
	{
		v.str[v.j] = malloc((data->g_x + 1) * sizeof(char));
		if (!v.str[v.j])
		{
			ft_free_all(v.str);
			ft_free_b(data, 2);
		}
		v.b = 0;
		while (data->map[v.j][v.b])
		{
			v.str[v.j][v.b] = data->map[v.j][v.b];
			v.b++;
		}
		v.str[v.j][v.b] = '\0';
		v.j++;
	}
	return (v.str);
}

void	s_valid_path_b(char **p)
{
	int		f;
	int		x;
	int		y;

	f = 0;
	y = 0;
	while (p[y])
	{
		x = 0;
		while (p[y][x])
		{
			if (p[y][x] == 'P')
				t_valid_path_b(p, y, x, &f);
			x++;
		}
		y++;
	}
	if (f)
		s_valid_path_b(p);
}

void	t_valid_path_b(char **p, int y, int x, int *f)
{
	if (p[y][x - 1] != '1' && p[y][x - 1] != 'P')
	{
		*f = 1;
		p[y][x - 1] = 'P';
	}
	if (p[y][x + 1] != '1' && p[y][x + 1] != 'P')
	{
		*f = 1;
		p[y][x + 1] = 'P';
	}
	if (p[y - 1][x] != '1' && p[y - 1][x] != 'P')
	{
		*f = 1;
		p[y - 1][x] = 'P';
	}
	if (p[y + 1][x] != '1' && p[y + 1][x] != 'P')
	{
		*f = 1;
		p[y + 1][x] = 'P';
	}
}

int	end_path_b(char **p)
{
	int		x;
	int		y;
	int		e;
	int		c;

	y = 0;
	e = 0;
	c = 0;
	while (p[y])
	{
		x = 0;
		while (p[y][x])
		{	
			if (p[y][x] == 'E')
				e += 1;
			if (p[y][x] == 'C')
				c += 1;
			x++;
		}
		y++;
	}
	if (e != 0 || c != 0)
		return (0);
	return (1);
}
