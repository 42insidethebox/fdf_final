/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 01:40:34 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 01:55:14 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "fdf.h"
#include "libft.h"

int	atoi_base_hex(const char *s, int default_color)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	if (!s)
		return (default_color);
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i += 2;
	while (s[i])
	{
		result <<= 4;
		if (s[i] >= '0' && s[i] <= '9')
			result += s[i] - '0';
		else if (s[i] >= 'A' && s[i] <= 'F')
			result += s[i] - 'A' + 10;
		else if (s[i] >= 'a' && s[i] <= 'f')
			result += s[i] - 'a' + 10;
		else
			return (default_color);
		i++;
	}
	return ((int)result);
}

void	split_point_token(const char *token,
	char **h_str, char **c_str, char **comma)
{
	*comma = ft_strchr(token, ',');
	if (*comma)
	{
		**comma = '\0';
		*h_str = (char *)token;
		*c_str = *comma + 1;
	}
	else
	{
		*h_str = (char *)token;
		*c_str = NULL;
	}
}

int	parse_point(const char *token, int *z,
	int *color, int default_color)
{
	char	*comma;
	char	*h_str;
	char	*c_str;
	long	vz;

	if (!token || !*token)
		return (1);
	split_point_token(token, &h_str, &c_str, &comma);
	vz = ft_atol(h_str);
	if (vz < -2147483648 || vz > 2147483647)
		return (1);
	*z = (int)vz;
	if (comma)
		*color = atoi_base_hex(c_str, default_color);
	else
		*color = default_color;
	if (comma)
		*comma = ',';
	return (0);
}

int	process_point(t_map *map, char *token,
	int x, int row_idx)
{
	int		z;
	int		color;
	int		default_color;

	default_color = 0xFFFFFF;
	if (parse_point(token, &z, &color, default_color))
		return (1);
	map->matrix[row_idx][x] = z;
	update_min_max_z(map, z);
	return (0);
}

int	process_row_points(t_map *map,
	char **cols, int row_idx)
{
	int	x;

	x = 0;
	while (cols[x] && x < map->width)
	{
		if (process_point(map, cols[x], x, row_idx))
			return (1);
		x++;
	}
	return (0);
}
