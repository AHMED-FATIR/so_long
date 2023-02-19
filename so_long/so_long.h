/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:41:06 by afatir            #+#    #+#             */
/*   Updated: 2023/02/13 14:51:15 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft_gcl_ptf/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# define SIZE 33

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*image;
	char	**map;
	int		img_x;
	int		img_y;
	int		x;
	int		y;
	int		mv;
	int		clct;
	int		g_x;
	int		g_y;
}t_data;

typedef struct s_var {
	int		i;
	int		ln;
	int		len;
	int		fd;
	int		p;
	int		e;
	int		l;
	int		c;
	char	*v;
	int		j;
	int		b;
	char	**str;
	int		x;
	int		y;
	int		flag;
}t_var;

// so_long.c
void	ft_print_msg(int i);
// valid_map.c
int		ft_valid(char *file, t_data *data);
int		f_wall(char *file, t_data *data, int *ln, int *len);
int		ft_count(char *str);
void	ft_free(t_data *data, int i);
void	check(t_data *data);
// walls.c
int		first_w(char *str);
int		last_w(char *str);
int		side_w(char **str, int i, int ln);
int		valid_s(char c);
// symbols.c
int		ft_symbols(t_data *data);
int		ft_clct(t_data *data);
void	ft_close(t_data *data);
int		ft_chekmap(char *str);
int		e_valid_path(char **p);
// put_image.c
void	put_image(t_data *data);
void	ft_print_map(t_data *data);
void	print_image(t_data *data, int x, int y);
void	p_position(t_data *data);
// ft_evants.c
int		ft_hook(int key, t_data *data);
int		ft_ecs(t_data *data);
int		ft_mv(int key, t_data *data);
int		mv_down_and_up(t_data *dt, int i);
int		mv_left_and_right(t_data *dt, int i);
//valid_path.c
int		valid_path(t_data *data);
char	**f_valid_path(t_data *data);
void	s_valid_path(char **p);
void	t_valid_path(char **p, int y, int x, int *z);
int		end_path(char **p);
#endif