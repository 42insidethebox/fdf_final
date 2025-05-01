/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:02:43 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 02:14:19 by procha-r         ###   ########.fr       */
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

void	prepare_map_data_ctx(t_parse_ctx ctx, const char *filename)
{
	int	fd;

	*ctx.lines = malloc(sizeof(char *) * 10000);
	if (!*ctx.lines)
		error_exit("Error: lines malloc fail.\n");
	fd = open_map_file(filename);
	if (read_map_lines(fd, *ctx.lines, ctx.line_count, ctx.col_count))
	{
		close(fd);
		error_exit("Error: Invalid line in map.\n");
	}
	close(fd);
	if (init_map_struct(ctx.map, *ctx.line_count, *ctx.col_count))
		error_exit("Error: init_map_struct failed.\n");
}

int	parse_map(const char *filename, t_map *map)
{
	int		fd;
	int		line_count;
	int		col_count;
	char	**lines;

	lines = malloc(sizeof(char *) * 10000);
	if (!lines)
		error_exit("Error: lines malloc fail.\n");
	fd = open_map_file(filename);
	if (read_map_lines(fd, lines, &line_count, &col_count))
	{
		close(fd);
		error_exit("Error: Invalid line in map.\n");
	}
	close(fd);
	if (init_map_struct(map, line_count, col_count))
		error_exit("Error: init_map_struct failed.\n");
	parse_lines_into_matrix(map, lines, line_count);
	return (0);
}
