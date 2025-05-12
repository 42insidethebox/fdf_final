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
#include "libft.h"
#include <unistd.h>

int	check_args(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		write(1, "Usage: <filename> <mapfile.fdf>\n", 32);
		return (0);
	}
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
	error_exit("Error: file must end with .fdf\n");
	return (1);
}
