/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:43:33 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 12:44:20 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "utils.h"

void	test_draw_pixel(void)
{
	t_mlx	mlx_data;

	mlx_data.addr = malloc(800 * 600 * 4);
	mlx_data.line_len = 800 * 4;
	mlx_data.bpp = 32;
	put_pixel(&mlx_data, 100, 100, 0xFF00FF);
}
