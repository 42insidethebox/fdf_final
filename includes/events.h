/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:36:27 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/05/01 12:32:39 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fdf.h"

// hooks.c
void			setup_hooks(t_fdf *fdf);

// mouse_hook.c
int				mouse_hook(int button, int x, int y, void *param);

// key_hook.c
int				key_hook(int keycode, void *param);

// exit_hook.c
int				close_window(void *param);

#endif
