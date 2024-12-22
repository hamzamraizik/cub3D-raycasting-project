/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:56:36 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/07 16:35:13 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_itmap(char *line)
{
	if (line[0] == ' ' || line[0] == '1' || line[0] == '0')
		return (1);
	return (0);
}

int	map_clms(char *filename)
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
		if (is_itmap(line))
			i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	error_cleanup(char *msg, char **map, int i, int fd)
{
	int	j;

	printf("%s", msg);
	j = 0;
	while (j < i)
		free(map[j++]);
	free(map);
	close(fd);
	return (0);
}

int	process_map_line(char *line, t_map_data *data, int fd)
{
	if (is_itmap(line))
	{
		if (*(data->map_state) == 2)
		{
			return (error_cleanup("empty line in map\n", \
								data->map, *(data->i), fd));
		}
		removeendline(line);
		data->map[*(data->i)] = ft_strdup(line);
		if (!data->map[*(data->i)])
			return (error_cleanup("Error\n", data->map, *(data->i), fd));
		(*(data->i))++;
		*(data->map_state) = 1;
	}
	else if (*(data->map_state) == 1 && line[0] == '\n')
		*(data->map_state) = 2;
	return (1);
}

char	**fill_map(char *filename, int i, int line_count, int map_state)
{
	int			fd;
	char		**map;
	char		*line;
	t_map_data	data;

	1 && (map_state = 0, line_count = map_clms(filename));
	if (line_count == 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (err("opening file\n"), NULL);
	map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (error_cleanup("Error\n", NULL, 0, fd), NULL);
	data = (t_map_data){map, &i, &map_state};
	line = get_next_line(fd);
	while (line)
	{
		if (!process_map_line(line, &data, fd))
			return (free(line), NULL);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (close(fd), map);
}
