/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:16:28 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 01:22:48 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	validate_line(const char *line)
{
	if (!line || !*line)
		return (0);
	while (*line)
	{
		if ((*line >= '0' && *line <= '9') || *line == ' ' || *line == '-' \
			|| *line == '+' || *line == ',' || (*line >= 'A' && *line <= 'F') \
			|| (*line >= 'a' && *line <= 'f') || *line == 'x' || *line == 'X')
		{
			line++;
			continue ;
		}
		return (0);
	}
	return (1);
}

int	count_columns(const char *line)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (line[i] == ' ')
			in_word = 0;
		i++;
	}
	return (count);
}
