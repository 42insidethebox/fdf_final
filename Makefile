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

MLX_DIR     = minilibx-linux
LIBFT_DIR   = fdf_project/sources/libft

INCLUDES = -I./fdf_project/includes -I$(MLX_DIR) -I$(LIBFT_DIR) -Ifdf_project/sources/get_next_line

SRCS        =fdf_project/main.c \
              fdf_project/srcs/init_window.c \
              fdf_project/srcs/map/init_map_struct.c \
              fdf_project/srcs/map/init_map.c \
              fdf_project/srcs/map/parse_map.c \
              fdf_project/srcs/map/validate_map.c \
              fdf_project/srcs/map/map_utils.c \
              fdf_project/srcs/map/parse_point.c \
              fdf_project/srcs/map/parse_map_utils.c \
              fdf_project/srcs/draw/draw_wireframe.c \
              fdf_project/srcs/draw/draw_line.c \
              fdf_project/srcs/draw/draw_pixel.c \
              fdf_project/srcs/draw/image_utils.c \
              fdf_project/srcs/events/hooks.c \
              fdf_project/srcs/events/mouse_hook.c \
              fdf_project/srcs/events/key_hook.c \
              fdf_project/srcs/events/exit_hook.c \
              fdf_project/srcs/utils/error.c \
              fdf_project/srcs/utils/free_resources.c \
              fdf_project/srcs/utils/checks.c \
			  fdf_project/sources/get_next_line/get_next_line.c \
			  fdf_project/sources/get_next_line/get_next_line_utils.c

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
