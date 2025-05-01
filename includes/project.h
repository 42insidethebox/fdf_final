/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:27:23 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 12:34:55 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include "fdf.h"

// projection_iso.c
t_point2	project_iso(t_point3 p, const t_map *map, const t_mlx *mlx_data);

// projection_bonus.c
t_point2	project_parallel(t_point3 p, const t_map *map, \
	const t_mlx *mlx_data);
t_point2	project_conic(t_point3 p, const t_map *map, const t_mlx *mlx_data);

#endif
