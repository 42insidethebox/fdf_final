/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:58:49 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/29 09:53:16 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdlib.h>

static void	init_bresenham(t_bresenham *b, t_point2 start, \
	t_point2 end, int color)
{
	b->x0 = (int)start.x;
	b->y0 = (int)start.y;
	b->x1 = (int)end.x;
	b->y1 = (int)end.y;
	b->dx = abs(b->x1 - b->x0);
	b->dy = -abs(b->y1 - b->y0);
	if (b->x0 < b->x1)
		b->sx = 1;
	else
		b->sx = -1;
	if (b->y0 < b->y1)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx + b->dy;
	b->color = color;
}

static void	step_bresenham(t_bresenham *b)
{
	b->e2 = 2 * b->err;
	if (b->e2 >= b->dy)
	{
		b->err += b->dy;
		b->x0 += b->sx;
	}
	if (b->e2 <= b->dx)
	{
		b->err += b->dx;
		b->y0 += b->sy;
	}
}

void	draw_line(t_mlx *mlx, t_point2 start, t_point2 end, int color)
{
	t_bresenham	b;

	init_bresenham(&b, start, end, color);
	while (1)
	{
		put_pixel(mlx, b.x0, b.y0, b.color);
		if (b.x0 == b.x1 && b.y0 == b.y1)
			break ;
		step_bresenham(&b);
	}
}
