/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:12:44 by procha-r          #+#    #+#             */
/*   Updated: 2025/03/02 18:12:48 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to print an error message and exit the program
void	error_exit(const char *message)
{
	if (message)
		write(2, message, strlen(message));
	exit(EXIT_FAILURE);
}
