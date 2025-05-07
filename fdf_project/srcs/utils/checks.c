/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:28:31 by procha-r          #+#    #+#             */
/*   Updated: 2025/03/02 20:57:04 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

int	check_args(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		write(1, "Usage: <filename> <mapfile.fdf>\n", 32);
		return (0);
	}
	return (1);
}

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
