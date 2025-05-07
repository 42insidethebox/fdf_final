/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:29:57 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/30 23:41:02 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "utils.h"
#include "libft.h"
#include <stdlib.h>

static void	rollback_partial_alloc(int **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static int	allocate_matrix_rows(int **matrix, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		matrix[i] = ft_calloc(width, sizeof(int));
		if (!matrix[i])
		{
			rollback_partial_alloc(matrix, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_map_struct(t_map *map, int height, int width)
{
	map->height = height;
	map->width = width;
	map->matrix = malloc(sizeof(int *) * height);
	if (!map->matrix)
		return (1);
	if (allocate_matrix_rows(map->matrix, height, width))
		return (1);
	map->z_min = 0;
	map->z_max = 0;
	return (0);
}
