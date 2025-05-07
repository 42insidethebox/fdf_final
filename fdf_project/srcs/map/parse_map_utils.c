/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 02:33:00 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 02:14:13 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "utils.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void	strip_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error: cannot open map file.\n");
	return (fd);
}

static int	handle_valid_line(char *line, char **lines,
	int *line_count, int *col_count)
{
	int	cols;

	strip_newline(line);
	if (!validate_line(line))
	{
		write(2, "💥 Invalid line rejected:\n", 26);
		write(2, line, strlen(line));
		write(2, "\n", 1);
		free(line);
		return (1);
	}
	lines[*line_count] = line;
	cols = count_columns(line);
	if (cols > *col_count)
		*col_count = cols;
	(*line_count)++;
	if (*line_count >= 10000)
		error_exit("Error: too many lines.\n");
	return (0);
}

int	read_map_lines(int fd, char **lines,
	int *line_count, int *col_count)
{
	char	*line;

	*line_count = 0;
	*col_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (handle_valid_line(line, lines, line_count, col_count))
			return (1);
		line = get_next_line(fd);
	}
	return (0);
}

void	parse_lines_into_matrix(t_map *map, char **lines, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		if (fill_matrix_row(map, lines[i], i))
			error_exit("Error: fill_matrix_row fail\n");
		free(lines[i]);
		i++;
	}
	free(lines);
}
