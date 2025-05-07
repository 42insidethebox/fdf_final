/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:41:44 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:45 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "utils.h"
#include <stdlib.h>

int	close_window(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	free_all(&fdf->map, &fdf->mlx);
	exit(0);
	return (0);
}
