/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:16:59 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 01:44:49 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "utils.h"
#include <stdlib.h>
#include <limits.h>

int	fill_matrix_row(t_map *map, char *line, int row_idx)
{
	char	**cols;
	int		ret;

	ret = 0;
	cols = ft_split(line, ' ');
	if (!cols)
		return (1);
	if (process_row_points(map, cols, row_idx))
		ret = 1;
	free_split(cols);
	return (ret);
}
