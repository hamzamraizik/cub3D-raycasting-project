/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:39:29 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:04:44 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	isspace(int c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	if_only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	colums_len(const char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		err("opening file\n");
		return (0);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	*removeendline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		i++;
	}
	return (line);
}

int	has_cub_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strcmp(filename + len - 4, ".cub") == 0)
	{
		if (len - 4 == 0)
			return (0);
		return (1);
	}
	err("Invalid file extension\n");
	return (0);
}
