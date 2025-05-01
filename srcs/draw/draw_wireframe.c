/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:21:09 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 01:32:18 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "fdf.h"
#include <math.h>

static int	get_altitude_color(int z, int z_min, int z_max)
{
	float	ratio;
	int		red;
	int		green;
	int		blue;

	if (z_min == z_max)
		return (0xFFFFFF);
	ratio = (float)(z - z_min) / (float)(z_max - z_min);
	if (ratio < 0.0f)
		ratio = 0.0f;
	if (ratio > 1.0f)
		ratio = 1.0f;
	red = (int)(255 * ratio);
	green = 0;
	blue = (int)(255 * (1.0f - ratio));
	return ((red << 16) | (green << 8) | blue);
}

static t_point2	project_point(t_point3 pt, const t_mlx *mlx_data, int proj)
{
	t_point2	p;
	float		angle;
	float		iso_x;
	float		iso_y;

	if (proj == PROJ_ISOMETRIC)
	{
		angle = 0.523599f;
		iso_x = (pt.x - pt.y) * cosf(angle);
		iso_y = -pt.z + (pt.x + pt.y) * sinf(angle);
		p.x = iso_x * mlx_data->zoom + mlx_data->offset_x;
		p.y = iso_y * mlx_data->zoom + mlx_data->offset_y;
	}
	else
	{
		p.x = pt.x * mlx_data->zoom + mlx_data->offset_x;
		p.y = pt.y * mlx_data->zoom + mlx_data->offset_y - (pt.z * 0.05f);
	}
	return (p);
}

static void	draw_right(t_wire_args *args)
{
	t_point3	pt1;
	t_point3	pt2;

	pt1.x = args->x;
	pt1.y = args->y;
	pt1.z = args->map->matrix[args->y][args->x];
	pt2.x = args->x + 1;
	pt2.y = args->y;
	pt2.z = args->map->matrix[args->y][args->x + 1];
	draw_line(args->mlx, project_point(pt1, args->mlx, args->proj), \
		project_point(pt2, args->mlx, args->proj), args->color);
}

static void	draw_bottom(t_wire_args *args)
{
	t_point3	pt1;
	t_point3	pt2;

	pt1.x = args->x;
	pt1.y = args->y;
	pt1.z = args->map->matrix[args->y][args->x];
	pt2.x = args->x;
	pt2.y = args->y + 1;
	pt2.z = args->map->matrix[args->y + 1][args->x];
	draw_line(args->mlx, project_point(pt1, args->mlx, args->proj), \
		project_point(pt2, args->mlx, args->proj), args->color);
}

void	draw_wireframe(const t_map *map, t_mlx *mlx_data, int projection)
{
	t_wire_args	args;

	args.map = map;
	args.mlx = mlx_data;
	args.proj = projection;
	args.y = 0;
	while (args.y < map->height)
	{
		args.x = 0;
		while (args.x < map->width)
		{
			args.color = get_altitude_color(map->matrix[args.y][args.x], \
				map->z_min, map->z_max);
			if (args.x < map->width - 1)
				draw_right(&args);
			if (args.y < map->height - 1)
				draw_bottom(&args);
			args.x++;
		}
		args.y++;
	}
}
