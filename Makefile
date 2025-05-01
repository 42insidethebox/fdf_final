# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 13:28:23 by procha            #+#    #+#              #
#    Updated: 2025/04/29 17:50:00 by procha-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ======================= VARIABLES ======================= #

NAME        = fdf

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

MLX_DIR     = sources/minilibx-linux
LIBFT_DIR   = sources/libft

INCLUDES = -I./includes -I$(MLX_DIR) -I$(LIBFT_DIR) -Isources/get_next_line

SRCS        = main.c \
              srcs/init_window.c \
              srcs/map/init_map_struct.c \
              srcs/map/init_map.c \
              srcs/map/parse_map.c \
              srcs/map/validate_map.c \
              srcs/map/map_utils.c \
              srcs/map/parse_point_utils.c \
              srcs/map/parse_map_utils.c \
              srcs/draw/draw_wireframe.c \
              srcs/draw/draw_line.c \
              srcs/draw/draw_pixel.c \
              srcs/draw/image_utils.c \
              srcs/events/hooks.c \
              srcs/events/mouse_hook.c \
              srcs/events/key_hook.c \
              srcs/events/exit_hook.c \
              srcs/utils/error.c \
              srcs/utils/free_resources.c \
              srcs/utils/checks.c \
			  sources/get_next_line/get_next_line.c \
			  sources/get_next_line/get_next_line_utils.c

OBJS        = $(SRCS:.c=.o)

# ======================= RULES ======================= #

all: $(NAME)

$(NAME): $(OBJS)
	@make --no-print-directory -C $(MLX_DIR)
	@make --no-print-directory -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lXext -lX11 -lm -lbsd -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make --no-print-directory -C $(MLX_DIR) clean
	@make --no-print-directory -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
