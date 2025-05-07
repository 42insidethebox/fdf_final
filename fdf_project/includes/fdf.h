/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:44:09 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 12:31:33 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

typedef struct s_point3
{
	float	x;
	float	y;
	float	z;
}	t_point3;

typedef struct s_point2
{
	float	x;
	float	y;
}	t_point2;

typedef enum e_projection
{
	PROJ_PARALLEL = 0,
	PROJ_ISOMETRIC
}	t_projection;

typedef struct s_map
{
	int		width;
	int		height;
	int		**matrix;
	int		z_min;
	int		z_max;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		win_width;
	int		win_height;
	float	zoom;
	float	offset_x;
	float	offset_y;
	float	angle_x;
	float	angle_y;
}	t_mlx;

typedef struct s_fdf
{
	t_map			map;
	t_mlx			mlx;
	t_projection	projection;
}	t_fdf;

int	init_map_struct(t_map *map, int height, int width);

#endif
