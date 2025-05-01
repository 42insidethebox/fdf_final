/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:48:17 by procha-r          #+#    #+#             */
/*   Updated: 2025/03/02 18:13:20 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "utils.h"

void	create_image(t_mlx *mlx, int width, int height)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	if (!mlx->img_ptr)
		error_exit("Failed to create image.\n");
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, \
		&mlx->line_len, &mlx->endian);
}

void	clear_image(t_mlx *mlx, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			put_pixel(mlx, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_image(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
