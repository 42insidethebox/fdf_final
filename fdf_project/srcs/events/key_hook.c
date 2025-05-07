/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:44:49 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/13 19:08:39 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "events.h"
#include "utils.h"
#include "draw.h"
#include <stdlib.h>

static void	handle_zoom_keys(t_fdf *fdf, int keycode)
{
	if (keycode == 24)
		fdf->mlx.zoom += 2.0f;
	if (keycode == 27)
		fdf->mlx.zoom -= 2.0f;
}

static void	handle_offset_keys(t_fdf *fdf, int keycode)
{
	if (keycode == 123)
		fdf->mlx.offset_x -= 20.0f;
	if (keycode == 124)
		fdf->mlx.offset_x += 20.0f;
	if (keycode == 125)
		fdf->mlx.offset_y += 20.0f;
	if (keycode == 126)
		fdf->mlx.offset_y -= 20.0f;
}

static void	handle_projection_keys(t_fdf *fdf, int keycode)
{
	if (keycode == 35)
		fdf->projection = PROJ_PARALLEL;
	if (keycode == 34)
		fdf->projection = PROJ_ISOMETRIC;
}

static void	redraw_scene(t_fdf *fdf)
{
	clear_image(&fdf->mlx, 1000, 800, 0x000000);
	draw_wireframe(&fdf->map, &fdf->mlx, fdf->projection);
	render_image(&fdf->mlx);
}

int	key_hook(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 53)
	{
		free_all(&fdf->map, &fdf->mlx);
		exit(0);
	}
	handle_zoom_keys(fdf, keycode);
	handle_offset_keys(fdf, keycode);
	handle_projection_keys(fdf, keycode);
	redraw_scene(fdf);
	return (0);
}
