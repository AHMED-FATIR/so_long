/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:28:32 by afatir            #+#    #+#             */
/*   Updated: 2023/02/13 14:47:36 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(t_data *data)
{
	char	**p;

	p = f_valid_path(data);
	s_valid_path(p);
	if (!end_path(p))
		return (ft_free_all(p), 0);
	return (ft_free_all(p), 1);
}

char	**f_valid_path(t_data *data)
{
	t_var	v;

	v.j = 0;
	v.str = ft_calloc((data->g_y + 1), sizeof(char *));
	if (!v.str)
		ft_free(data, 2);
	while (data->map[v.j])
	{
		v.str[v.j] = malloc((data->g_x + 1) * sizeof(char));
		if (!v.str[v.j])
		{
			ft_free_all(v.str);
			ft_free(data, 2);
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

void	s_valid_path(char **p)
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
				t_valid_path(p, y, x, &f);
			x++;
		}
		y++;
	}
	if (f)
		s_valid_path(p);
}

void	t_valid_path(char **p, int y, int x, int *f)
{
	if (p[y][x - 1] != '1' && p[y][x - 1] != 'P' && p[y][x - 1] != 'E')
	{
		*f = 1;
		p[y][x - 1] = 'P';
	}
	if (p[y][x + 1] != '1' && p[y][x + 1] != 'P' && p[y][x + 1] != 'E')
	{
		*f = 1;
		p[y][x + 1] = 'P';
	}
	if (p[y - 1][x] != '1' && p[y - 1][x] != 'P' && p[y - 1][x] != 'E')
	{
		*f = 1;
		p[y - 1][x] = 'P';
	}
	if (p[y + 1][x] != '1' && p[y + 1][x] != 'P' && p[y + 1][x] != 'P')
	{
		*f = 1;
		p[y + 1][x] = 'P';
	}
}

int	end_path(char **p)
{
	int		x;
	int		y;
	int		c;

	y = 0;
	c = 0;
	while (p[y])
	{
		x = 0;
		while (p[y][x])
		{	
			if (p[y][x] == 'C')
				c += 1;
			x++;
		}
		y++;
	}
	if (c != 0 || !e_valid_path(p))
		return (0);
	return (1);
}
