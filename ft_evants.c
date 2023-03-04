/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:53:58 by afatir            #+#    #+#             */
/*   Updated: 2023/02/05 21:45:55 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mv_left_and_right(t_data *dt, int i)
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

int	mv_down_and_up(t_data *dt, int i)
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

int	ft_mv(int key, t_data *dt)
{
	if ((key == 0 || key == 123) && (dt->map[dt->y][dt->x - 1] == 'E'))
		ft_clct(dt);
	else if ((key == 0 || key == 123) && (dt->map[dt->y][dt->x - 1] != '1'))
		mv_left_and_right(dt, 1);
	if ((key == 2 || key == 124) && (dt->map[dt->y][dt->x + 1] == 'E'))
		ft_clct(dt);
	else if ((key == 2 || key == 124) && (dt->map[dt->y][dt->x + 1] != '1'))
		mv_left_and_right(dt, 2);
	if ((key == 1 || key == 125) && (dt->map[dt->y + 1][dt->x] == 'E'))
		ft_clct(dt);
	else if ((key == 1 || key == 125) && (dt->map[dt->y + 1][dt->x] != '1'))
		mv_down_and_up(dt, 1);
	if ((key == 13 || key == 126) && (dt->map[dt->y - 1][dt->x] == 'E'))
		ft_clct(dt);
	else if ((key == 13 || key == 126) && (dt->map[dt->y - 1][dt->x] != '1'))
		mv_down_and_up(dt, 2);
	return (0);
}

int	ft_ecs(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_free(data, 7);
	return (0);
}

int	ft_hook(int key, t_data *data)
{
	int		i;
	char	*p;

	i = data->mv;
	if (key == 53)
		ft_ecs(data);
	else
		ft_mv(key, data);
	if (i != data->mv)
		ft_printf("step: %d\n", (i + 1));
	ft_print_map(data);
	p = ft_itoa(data->mv);
	mlx_string_put(data->mlx, data->mlx_win, (SIZE) + 10, 15, 0xffffff, p);
	free (p);
	return (0);
}
