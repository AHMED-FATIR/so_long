/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 04:55:25 by afatir            #+#    #+#             */
/*   Updated: 2023/02/07 11:56:37 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_b(t_data *data, int i)
{
	size_t	j;

	j = 0;
	while (data->map[j])
	{
		free(data->map[j]);
		data->map[j] = NULL;
		j++;
	}
	free(data->map);
	ft_print_msg_b(i);
}

int	ft_count_b(char *str)
{
	int		fd;
	char	*p;
	int		count;

	count = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit(1);
	while (1)
	{
		p = get_next_line(fd);
		if (p == NULL)
		{
			close(fd);
			break ;
		}
		count++;
		free(p);
	}
	return (count);
}

int	f_wall_b(char *file, t_data *data, int *ln, int *len)
{
	int		df;

	data->g_y = ft_count_b(file);
	*len = data->g_y;
	data->map = (char **)ft_calloc((data->g_y + 1), sizeof(char *));
	if (!data->map)
		return (0);
	df = open(file, O_RDONLY);
	if (df < 0)
		return (ft_free_b(data, 3), 0);
	data->map[0] = get_next_line(df);
	if (!data->map[0] || !first_w_b(data->map[0]))
		return (ft_free_b(data, 3), 0);
	*ln = ft_strlen(data->map[0]);
	data->g_x = (*ln) - 1;
	close(df);
	return (1);
}

int	ft_valid_b(char *file, t_data *data)
{
	t_var		v;

	v.i = 1;
	if (!f_wall_b(file, data, &v.ln, &v.len))
		return (0);
	v.fd = open(file, O_RDONLY);
	if (v.fd < 0)
		return (0);
	v.v = get_next_line(v.fd);
	free(v.v);
	while (v.i < v.len)
	{
		data->map[v.i] = get_next_line(v.fd);
		if (!data->map[v.i])
			break ;
		if (!side_w_b(data->map, v.i, (v.ln - 1)))
			return (ft_free_b(data, 4), 0);
		v.i++;
	}
	if (!last_w_b(data->map[v.i - 1]))
		return (ft_free_b(data, 5), 0);
	close(v.fd);
	return (1);
}

void	check_b(t_data *data)
{
	if (!data->image)
	{
		ft_free_b(data, 8);
	}
}
