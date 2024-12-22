/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:43:05 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:06:53 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**fillmap(char *filename)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (err("opening file\n"), NULL);
	map = (char **)gc_malloc(sizeof(char *) * (colums_len(filename) + 1));
	if (!map)
	{
		err("allocating memory\n");
		return (close(fd), NULL);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strdupp(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (close(fd), map);
}

int	handle_floor_line(int *flor_set, char *line)
{
	if (*flor_set)
		return (err("Duplicate F line\n"), 1);
	*flor_set = 1;
	if (!is_valid_rgb(line + 1))
		return (err("Invalid F\n"), 1);
	return (0);
}

int	handle_ceiling_line(int *ceiling_set, char *line)
{
	if (*ceiling_set)
		return (err("Duplicate C line\n"), 1);
	*ceiling_set = 1;
	if (!is_valid_rgb(line + 1))
		return (err("Invalid C\n"), 1);
	return (0);
}

int	check_missing_flor_ceiling(int flor_set, int ceiling_set)
{
	if (!flor_set || !ceiling_set)
		return (err(" Missing F or C line\n"), 1);
	return (0);
}

int	validate_flor_and_ceiling(char **line)
{
	int	i;
	int	flor_set;
	int	ceiling_set;

	i = 0;
	flor_set = 0;
	ceiling_set = 0;
	while (line[i])
	{
		line[i] = removespaces(line[i]);
		if (is_floor_line(line[i]) && handle_floor_line(&flor_set, line[i]))
			return (1);
		else if (is_ceiling_line(line[i])
			&& handle_ceiling_line(&ceiling_set, line[i]))
			return (1);
		else if (is_itmap(line[i]) && (!flor_set || !ceiling_set))
			return (err(" Missing F or C line\n"), 1);
		i++;
	}
	return (check_missing_flor_ceiling(flor_set, ceiling_set));
}
