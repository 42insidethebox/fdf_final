/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:42:58 by procha-r          #+#    #+#             */
/*   Updated: 2025/03/02 13:04:58 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "events.h"

void	setup_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx.win_ptr, key_hook, fdf);
	mlx_hook(fdf->mlx.win_ptr, 17, 0, close_window, fdf);
}
