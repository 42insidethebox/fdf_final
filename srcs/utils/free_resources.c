/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:32:06 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/13 13:11:53 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map->matrix)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	map->matrix = NULL;
}

void	free_all(t_map *map, t_mlx *mlx_data)
{
	if (map)
		free_map(map);
	if (mlx_data)
	{
		if (mlx_data->img_ptr)
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img_ptr);
		if (mlx_data->win_ptr)
			mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	}
}
