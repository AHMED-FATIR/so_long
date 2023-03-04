/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evants_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:53:58 by afatir            #+#    #+#             */
/*   Updated: 2023/02/04 16:03:42 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mv_left_and_right_b(t_data *dt, int i)
{
	if (i == 1)
	{
		dt->map[dt->y][dt->x] = '0';
		dt->x -= 1;
		dt->map[dt->y][dt->x] = 'P';
		dt->mv++;
	}
	else if (i == 2)
	{
		dt->map[dt->y][dt->x] = '0';
		dt->x += 1;
		dt->map[dt->y][dt->x] = 'P';
		dt->mv++;
	}
	return (0);
}

int	mv_down_and_up_b(t_data *dt, int i)
{
	if (i == 1)
	{
		dt->map[dt->y][dt->x] = '0';
		dt->y += 1;
		dt->map[dt->y][dt->x] = 'P';
		dt->mv++;
	}
	else if (i == 2)
	{
		dt->map[dt->y][dt->x] = '0';
		dt->y -= 1;
		dt->map[dt->y][dt->x] = 'P';
		dt->mv++;
	}
	return (0);
}

int	ft_mv_b(int key, t_data *dt)
{
	if ((key == 0 || key == 123) && (dt->map[dt->y][dt->x - 1] == 'E' \
		|| dt->map[dt->y][dt->x - 1] == 'A'))
		ft_clct_b(dt, dt->map[dt->y][dt->x - 1]);
	else if ((key == 0 || key == 123) && (dt->map[dt->y][dt->x - 1] != '1'))
		mv_left_and_right_b(dt, 1);
	if ((key == 2 || key == 124) && (dt->map[dt->y][dt->x + 1] == 'E' \
		|| dt->map[dt->y][dt->x + 1] == 'A'))
		ft_clct_b(dt, dt->map[dt->y][dt->x + 1]);
	else if ((key == 2 || key == 124) && (dt->map[dt->y][dt->x + 1] != '1'))
		mv_left_and_right_b(dt, 2);
	if ((key == 1 || key == 125) && (dt->map[dt->y + 1][dt->x] == 'E' \
		|| dt->map[dt->y + 1][dt->x] == 'A'))
		ft_clct_b(dt, dt->map[dt->y + 1][dt->x]);
	else if ((key == 1 || key == 125) && (dt->map[dt->y + 1][dt->x] != '1'))
		mv_down_and_up_b(dt, 1);
	if ((key == 13 || key == 126) && (dt->map[dt->y - 1][dt->x] == 'E' \
		|| dt->map[dt->y - 1][dt->x] == 'A'))
		ft_clct_b(dt, dt->map[dt->y - 1][dt->x]);
	else if ((key == 13 || key == 126) && (dt->map[dt->y - 1][dt->x] != '1'))
		mv_down_and_up_b(dt, 2);
	return (0);
}

int	ft_ecs_b(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_free_b(data, 7);
	return (0);
}

int	ft_hook_b(int key, t_data *data)
{
	int		i;
	char	*p;

	i = data->mv;
	if (key == 53)
		ft_ecs_b(data);
	else
		ft_mv_b(key, data);
	ft_print_map_b(data);
	p = ft_itoa(data->mv);
	mlx_string_put(data->mlx, data->mlx_win, (SIZE) + 5, 15, 0xfffffff, p);
	free (p);
	return (0);
}
