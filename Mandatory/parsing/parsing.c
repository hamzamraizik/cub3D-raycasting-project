/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:37:33 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:17:42 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*strtrim(char *s)
{
	char	*start;
	char	*end;

	start = s;
	end = s + ft_strlen(s) - 1;
	if (*end == '\n')
		end--;
	while (isspace(*start))
		start++;
	while (isspace(*end))
		end--;
	return (substr(start, 0, end - start + 1));
}

int	spaces_before_after_comma(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] && !isspace(line[i]))
			return (0);
		while (isdigit(line[i]))
			i++;
		i++;
	}
	return (1);
}

int	how_many_commas(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	is_valid_rgb(char *line)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if (line[0] != ' ')
		return (0);
	line = removespaces(line);
	if (ft_countword(line, ',') != 3 || how_many_commas(line) != 2)
		return (err("RGB value takes 3 arguments!\n"), 0);
	if (ft_strchr(line, '\t') != NULL)
		return (0);
	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (err("Missin arguments\n"), ft_free(rgb), 0);
	if (!is_digit_space(rgb[0]) || !is_digit_space(rgb[1]) \
		|| !is_digit_space(rgb[2]) || spaces_before_after_comma(rgb[0]) \
		|| spaces_before_after_comma(rgb[1]) \
		|| spaces_before_after_comma(rgb[2]))
		return (ft_free(rgb), 0);
	1 && (r = ft_atoi(rgb[0]), g = ft_atoi(rgb[1]), b = ft_atoi(rgb[2]));
	ft_free(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (err("invalid RGB value\n"), 0);
	return (1);
}

int	is_valid_direction(char *line)
{
	const char	*valid_directions[] = {"WE", "EA", "SO", "NO", NULL};
	int			i;
	char		*trimmed_line;
	char		*after_direction;

	trimmed_line = removespaces(line);
	i = 0;
	while (valid_directions[i])
	{
		if (ft_strncmp(trimmed_line, valid_directions[i], \
			ft_strlen(valid_directions[i])) == 0)
		{
			after_direction = trimmed_line + ft_strlen(valid_directions[i]);
			while (isspace(*after_direction))
				after_direction++;
			if (ft_strlen(after_direction) <= 1 \
				|| ft_strchr(after_direction, '\t') != NULL)
				return (printf("Error \nInvalid path :%s\n", line), 0);
			return (1);
		}
		i++;
	}
	return (0);
}
