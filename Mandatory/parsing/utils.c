/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:45:14 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/07 17:21:35 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'W'
		|| c == 'E' || c == 'N' || c == 'S');
}

void	set_p_direction(char c, t_map *map)
{
	if (c == 'N')
		map->p_direction = NORTH;
	else if (c == 'S')
		map->p_direction = SOUTH;
	else if (c == 'W')
		map->p_direction = WEST;
	else if (c == 'E')
		map->p_direction = EAST;
}

int	duplicate_player(char **map)
{
	int	i;
	int	player_count;
	int	j;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'W' || map[i][j] == 'E')
			{
				player_count++;
				if (player_count > 1)
					return (err("Duplicate player\n"), 1);
			}
			j++;
		}
		i++;
	}
	if (player_count == 0)
		return (err("No player found\n"), 1);
	return (0);
}

int	parse_map(char **map, char *filename)
{
	size_t	largest_line;
	int		i;

	largest_line = calculate_largest_line(map);
	i = 0;
	if (duplicate_player(map) || !check_first_and_last_walls(map, filename)
		|| !validate_first_and_last_lines(map[0], 1))
		return (1);
	pad_map_lines(map, largest_line);
	while (map[i])
	{
		if (!validate_first_and_last_lines(map[i], 0))
			return (printf("Error:\nInvalid character on line %d\n", i), 1);
		if (!validate_first_and_last_lines(map[i], 1))
			return (printf("Error:\nInvalid character on line %d\n", i), 1);
		if (validate_line(map[i], largest_line)
			|| check_adjacent_spaces(map, i, largest_line))
			return (1);
		i++;
	}
	return (0);
}

int	validate_first_and_last_lines(char *line, int is_first)
{
	if (is_first)
		return ((line[0] == '1' || line[0] == ' '));
	return ((line[ft_strlen(line) - 1] == '1' \
			|| line[ft_strlen(line) - 1] == ' '));
}
