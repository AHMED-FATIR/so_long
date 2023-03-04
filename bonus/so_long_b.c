/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:23:32 by afatir            #+#    #+#             */
/*   Updated: 2023/02/05 21:33:20 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_msg_b(int i)
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
		if (!ft_chekmap_b(av[1]))
			ft_print_msg_b(1);
		if (!ft_valid_b(av[1], &data))
			ft_print_msg_b(2);
		if (!ft_symbols_b(&data))
			return (ft_free_b(&data, 6), 0);
		p_position_b(&data);
		if (!valid_path_b(&data))
			return (ft_free_b(&data, 2), 0);
		put_image_b(&data);
	}
	else
		ft_print_msg_b(0);
	return (0);
}
