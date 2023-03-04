# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afatir <afatir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 17:24:59 by afatir            #+#    #+#              #
#    Updated: 2023/03/04 18:20:05 by afatir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
BNAME	= so_long_bonus

LIB_FT	= ./libft_gcl_ptf/
LIB_FT_A= ./libft_gcl_ptf/libft_gcl_ptf.a

CFLAGS	= -Wall -Werror -Wextra
CC		= cc
MLX		= -lmlx -framework OpenGL -framework AppKit

MOBJS	= ${SRCS:%.c=%.o}
BOBJS	= ${SRCS_B:%.c=%.o}

SRCS	= so_long.c valid_map.c symbols.c walls.c put_image.c ft_evants.c valid_path.c

SRCS_B	= bonus/so_long_b.c bonus/valid_map_b.c bonus/symbols_b.c bonus/walls_b.c \
			bonus/put_image_b.c bonus/ft_evants_b.c bonus/valid_path_b.c

all :		$(NAME)
			@make -C $(LIB_FT)

$(NAME) :	$(MOBJS)
			@make -s -C $(LIB_FT)
			@$(CC) $(CFLAGS) $(LIB_FT_A) $(MLX) $(MOBJS) -o $(NAME)

%.o:	%.c so_long.h bonus/so_long_bonus.h
			$(CC) $(CFLAGS)  -c $< -o $@

bonus:		$(BNAME)
			@make -C $(LIB_FT)
$(BNAME):	$(BOBJS)
			@make -s -C $(LIB_FT)
			@$(CC) $(CFLAGS) $(LIB_FT_A) $(MLX) $(BOBJS) -o $(BNAME)
clean:
			@make clean -s -C $(LIB_FT)
			@rm -f $(MOBJS) $(BOBJS)

fclean: 	clean
			@make fclean -s -C $(LIB_FT)
			@rm -f $(NAME) $(BNAME)

re: 		fclean all