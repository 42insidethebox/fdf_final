/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:36:22 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/05/01 12:29:11 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "fdf.h"

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_bresenham;

typedef struct s_wire_args
{
	t_mlx			*mlx;
	const t_map		*map;
	int				x;
	int				y;
	int				color;
	int				proj;
}	t_wire_args;

// draw_wireframe.c
void	draw_wireframe(const t_map *map, t_mlx *mlx_data, int projection);

// draw_line.c
void	draw_line(t_mlx *mlx_data, t_point2 start, t_point2 end, int color);

// draw_pixel.c
void	put_pixel(t_mlx *mlx_data, int x, int y, int color);

// image_utils.c
void	create_image(t_mlx *mlx_data, int width, int height);
void	clear_image(t_mlx *mlx, int width, int height, int color);
void	render_image(t_mlx *mlx_data);

#endif
