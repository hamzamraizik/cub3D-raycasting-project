/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:45:40 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:13:57 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	calculate_largest_line(char **map)
{
	int	largest_line;
	int	i;
	int	length;

	largest_line = 0;
	i = 0;
	while (map[i])
	{
		length = ft_strlen(map[i]);
		if (length > largest_line)
			largest_line = length;
		i++;
	}
	return (largest_line);
}

char	*pad_line_with_spaces(char *line, int target_length)
{
	int		j;
	char	*new_line;

	new_line = malloc(target_length + 1);
	if (!new_line)
	{
		err("Memory allocation failed\n");
		return (NULL);
	}
	ft_strcpy(new_line, line);
	j = ft_strlen(line);
	while (j < target_length)
	{
		new_line[j] = ' ';
		j++;
	}
	new_line[target_length] = '\0';
	return (new_line);
}

int	validate_line(char *line, int largest_line)
{
	int	j;

	j = 0;
	while (j < largest_line)
	{
		if (!is_valid_char(line[j]))
		{
			printf("Error\n");
			printf("Invalid character '%c' in map line\n", line[j]);
			return (1);
		}
		j++;
	}
	return (0);
}
