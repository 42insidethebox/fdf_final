/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:42:48 by procha-r          #+#    #+#             */
/*   Updated: 2025/03/02 18:48:11 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "utils.h"
#include <stdlib.h>

void	update_min_max_z(t_map *map, int z_value)
{
	if (z_value < map->z_min)
		map->z_min = z_value;
	if (z_value > map->z_max)
		map->z_max = z_value;
}

int	get_z_min(const t_map *map)
{
	return (map->z_min);
}

int	get_zmax(const t_map *map)
{
	return (map->z_max);
}
