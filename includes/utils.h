/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:45:57 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 12:32:12 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fdf.h"

// error.c
void			error_exit(const char *message);

// free_resources.c
void			free_map(t_map *map);
void			free_all(t_map *map, t_mlx *mlx_data);

// checks.c
int				check_args(int argc, char **argv);
int				is_numeric(const char *str);
void			init_window(t_mlx *mlx_data, int width,
					int height, const char *title);

// extended libft
char			*ft_strchr(const char *s, int c);
long			ft_atol(const char *str);
char			**ft_split(char const *s, char c);
void			ft_free_split(char **split);

#endif
