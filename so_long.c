/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:23:32 by afatir            #+#    #+#             */
/*   Updated: 2023/03/04 18:05:03 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_msg(int i)
{
	if (i == 0)
		ft_printf("the number of arguments is invalid :(\n");
	if (i == 1)
		ft_printf("file name must end with (*.ber) :(\n");
	if (i == 2)
		ft_printf("the map or the path is invalid :(\n");
	if (i == 3)
		ft_printf("error in the first wall :(\n");
	if (i == 4)
		ft_printf("the side walls or the symbols is invalid :(\n");
	if (i == 5)
		ft_printf("the last wall is invalid :(\n");
	if (i == 6)
		ft_printf("the symbols is invalid :(\n");
	if (i == 8)
		ft_printf("mlx error :(\n");
	if (i == 7)
	{
		ft_printf("||||||| GAME CLOSED ||||||||\n");
		exit(0);
	}
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!ft_chekmap(av[1]))
			ft_print_msg(1);
		if (!ft_valid(av[1], &data))
			ft_print_msg(2);
		if (!ft_symbols(&data))
			return (ft_free(&data, 6), 0);
		p_position(&data);
		if (!valid_path(&data))
			return (ft_free(&data, 2), 0);
		put_image(&data);
	}
	else
		ft_print_msg(0);
	return (0);
}
