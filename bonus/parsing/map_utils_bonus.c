/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:16:27 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:14:33 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	ft_count_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	check_adjacent_space(int line_index, int j, char **map)
{
	if ((line_index > 0 && map[line_index - 1][j] == ' ') || \
		(map[line_index + 1] && map[line_index + 1][j] == ' ') || \
		(j > 0 && map[line_index][j - 1] == ' ') || \
		(map[line_index][j + 1] == ' '))
	{
		printf("Error\n");
		printf("Invalid placement of '%c' in line %d at column %d\n", \
				map[line_index][j], line_index, j);
		return (1);
	}
	return (0);
}

int	check_door_surrounding(int line_index, int j, char **map, int total_lines)
{
	if (line_index == 1 || line_index == total_lines - 2)
	{
		printf("Error\n");
		printf("Invalid placement of D in line %d at column %d\n", \
				line_index, j);
		return (1);
	}
	if (!((j > 0 && map[line_index][j - 1] == '1' && \
			map[line_index][j + 1] == '1') ||
			(line_index > 0 && map[line_index - 1][j] == '1' && \
			map[line_index + 1][j] == '1')))
	{
		printf("Error\n");
		printf("Door 'D' at line %d, column %d is not surrounded by walls\n", \
				line_index, j);
		return (1);
	}
	return (0);
}

int	check_adjacent_spaces(char **map, int line_index, int largest_line)
{
	int	total_lines;
	int	j;

	total_lines = ft_count_map(map);
	j = 0;
	while (j < largest_line)
	{
		if (map[line_index][j] == '0' || map[line_index][j] == 'N' || \
			map[line_index][j] == 'S' || map[line_index][j] == 'W' || \
			map[line_index][j] == 'E' || map[line_index][j] == 'D')
		{
			if (check_adjacent_space(line_index, j, map))
				return (1);
			if (map[line_index][j] == 'D' \
				&& check_door_surrounding(line_index, j, map, total_lines))
				return (1);
		}
		j++;
	}
	return (0);
}
