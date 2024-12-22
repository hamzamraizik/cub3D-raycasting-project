/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:16:27 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:18:05 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	if ((line_index > 0 && map[line_index - 1][j] == ' ') ||
		(map[line_index + 1] && map[line_index + 1][j] == ' ') ||
		(j > 0 && map[line_index][j - 1] == ' ') ||
		(map[line_index][j + 1] == ' '))
	{
		printf("Error \nInvalid placement of '%c' in line %d at column %d\n",
			map[line_index][j], line_index, j);
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
		if (map[line_index][j] == '0' || map[line_index][j] == 'N' ||
			map[line_index][j] == 'S' || map[line_index][j] == 'W' ||
			map[line_index][j] == 'E')
		{
			if (check_adjacent_space(line_index, j, map))
				return (1);
		}
		j++;
	}
	return (0);
}
