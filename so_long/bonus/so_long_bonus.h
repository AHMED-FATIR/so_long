/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:41:06 by afatir            #+#    #+#             */
/*   Updated: 2023/02/07 11:55:11 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft_gcl_ptf/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>	
# define SIZE 33

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*image;
	char	**map;
	int		img_x;
	int		img_y;
	int		g_x;
	int		g_y;
	int		x;
	int		y;
	int		mv;
	int		enm;
	int		clct;
}t_data;

typedef struct s_var {
	int		i;
	int		ln;
	int		len;
	int		fd;
	int		p;
	int		e;
	int		n;
	int		l;
	int		c;
	int		j;
	int		b;
	char	*v;
	char	**str;
}t_var;

// so_long_b.c
void	ft_print_msg_b(int i);
// valid_map_b.c
int		ft_valid_b(char *file, t_data *data);
int		f_wall_b(char *file, t_data *data, int *ln, int *len);
int		ft_count_b(char *str);
void	ft_free_b(t_data *data, int i);
void	check_b(t_data *data);
// walls_b.c
int		first_w_b(char *str);
int		last_w_b(char *str);
int		side_w_b(char **str, int i, int ln);
int		valid_s_b(char c);
// symbols_b.c
int		ft_symbols_b(t_data *data);
int		ft_clct_b(t_data *data, char c);
void	ft_close_b(t_data *data);
int		ft_chekmap_b(char *str);
// put_image_b.c
void	put_image_b(t_data *data);
void	ft_print_map_b(t_data *data);
void	print_image_b(t_data *data, int x, int y);
void	p_position_b(t_data *data);
// ft_evants_b.c
int		ft_hook_b(int key, t_data *data);
int		ft_ecs_b(t_data *data);
int		ft_mv_b(int key, t_data *data);
int		mv_down_and_up_b(t_data *dt, int i);
int		mv_left_and_right_b(t_data *dt, int i);
//valid_path_b.c
int		valid_path_b(t_data *data);
char	**f_valid_path_b(t_data *data);
void	s_valid_path_b(char **p);
void	t_valid_path_b(char **p, int y, int x, int *z);
int		end_path_b(char **p);

#endif