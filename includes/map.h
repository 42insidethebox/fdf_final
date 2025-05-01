/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:27:08 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 12:32:27 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <string.h>
# include "fdf.h"

// parse_map.c
int				parse_map(const char *filename, t_map *map);

// validate_map.c
int				validate_line(const char *line);
int				count_columns(const char *line);

// init_map.c
int				init_map_struct(t_map *map, int height, int width);
int				allocate_matrix(t_map *map);
int				fill_matrix_row(t_map *map, char *line, int row_index);

// map_utils.c
void			update_min_max_z(t_map *map, int z_value);
int				get_z_min(const t_map *map);
int				get_z_max(const t_map *map);

// point parsing
int				atoi_base_hex(const char *s, int default_color);
void			split_point_token(const char *token,
					char **h_str, char **c_str, char **comma);
int				parse_point(const char *token, int *z,
					int *color, int default_color);
int				process_point(t_map *map, char *token,
					int x, int row_idx);
int				process_row_points(t_map *map,
					char **cols, int row_idx);

// parse_ctx struct
typedef struct s_parse_ctx
{
	t_map			*map;
	char			***lines;
	int				*line_count;
	int				*col_count;
}					t_parse_ctx;

// map_read.c
void			strip_newline(char *line);
int				open_map_file(const char *filename);
int				read_map_lines(int fd, char **lines,
					int *line_count, int *col_count);
void			parse_lines_into_matrix(t_map *map,
					char **lines, int line_count);
void			prepare_map_data_ctx(t_parse_ctx ctx,
					const char *filename);

#endif
