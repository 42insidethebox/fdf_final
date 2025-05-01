/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:52:20 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 00:09:03 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"
#include "map.h"
#include "draw.h"
#include "events.h"
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (!check_args(argc, argv))
		return (1);
	fdf.map.width = 0;
	fdf.map.height = 0;
	fdf.map.matrix = NULL;
	fdf.map.z_min = 0;
	fdf.map.z_max = 0;
	fdf.projection = PROJ_ISOMETRIC;
	if (parse_map(argv[1], &fdf.map) != 0)
		return (1);
	printf("Map dimensions: width = %d, height = %d\n", fdf.map.width, fdf.map.height);
	printf("Z range: z_min = %d, z_max = %d\n", fdf.map.z_min, fdf.map.z_max);		
	init_window(&fdf.mlx, 800, 800, "FDF - Wireframe");
	draw_wireframe(&fdf.map, &fdf.mlx, fdf.projection);
	render_image(&fdf.mlx);
	setup_hooks(&fdf);
	mlx_loop(fdf.mlx.mlx_ptr);
	free_all(&fdf.map, &fdf.mlx);
	return (0);
}
