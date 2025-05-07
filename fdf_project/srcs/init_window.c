/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:35:26 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/30 23:53:15 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "draw.h"
#include "events.h"

void	init_window(t_mlx *mlx_data, int width, int height, const char *title)
{
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		error_exit("Failed to initialize MLX\n");
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, width, \
		height, (char *)title);
	if (!mlx_data->win_ptr)
	{
		free_all(NULL, mlx_data);
		error_exit("Failed to create window.\n");
	}
	mlx_data->zoom = 20.0;
	mlx_data->offset_x = width / 2;
	mlx_data->offset_y = height / 2;
	mlx_data->angle_x = 0.0;
	mlx_data->angle_y = 0.0;
	mlx_data->win_width = width;
	mlx_data->win_height = height;
	create_image(mlx_data, width, height);
}
