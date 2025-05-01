/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:06:03 by procha-r          #+#    #+#             */
/*   Updated: 2025/03/02 18:12:29 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "draw.h"

int	mouse_hook(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	(void)x;
	(void)y;
	if (button == 4)
		fdf->mlx.zoom += 2.0f;
	else if (button == 5)
		fdf->mlx.zoom -= 2.0f;
	clear_image(&fdf->mlx, 1000, 800, 0x000000);
	draw_wireframe(&fdf->map, & fdf->mlx, fdf->projection);
	render_image(&fdf->mlx);
	return (0);
}
