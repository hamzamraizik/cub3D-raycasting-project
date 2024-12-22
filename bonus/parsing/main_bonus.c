/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:58:30 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:05:05 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	fill_diractions(t_diraction *directions, char *filename)
{
	int		fd;
	char	*line;

	1 && (fd = open(filename, O_RDONLY), line = get_next_line(fd));
	if (fd == -1 || !line)
		return (err("opening file\n"), 1);
	while (line)
	{
		line = removeendline(line);
		if (ft_strncmp(line, "NO ", 3) == 0)
			directions->no = gc_and_cpy(line + 3);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			directions->so = gc_and_cpy(line + 3);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			directions->we = gc_and_cpy(line + 3);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			directions->ea = gc_and_cpy(line + 3);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}

int	fill_floor_ceiling(t_colors *f, t_colors *c, char *filename)
{
	int		fd;
	char	**value;
	char	*line;

	1 && (fd = open(filename, O_RDONLY), line = get_next_line(fd));
	if (fd == -1 || !line)
		return (err("opening file\n"), 1);
	while (line)
	{
		if (ft_strncmp(line, "F ", 2) == 0)
		{
			1 && (value = ft_split(line + 2, ','), f->r = ft_atoi(value[0]), \
					f->g = ft_atoi(value[1]), f->b = ft_atoi(value[2]));
			ft_free(value);
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			1 && (value = ft_split(line + 2, ','), c->r = ft_atoi(value[0]), \
					c->g = ft_atoi(value[1]), c->b = ft_atoi(value[2]));
			ft_free(value);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}

void	find_player_pose(t_map *s_map, int *x, int *y)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = s_map->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				set_p_direction(map[i][j], s_map);
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	parsing(char *filename, t_map *map)
{
	if (!has_cub_extension(filename))
		return (1);
	if (is_valid(filename))
		return (1);
	map->map = fill_map(filename, 0, 0, 0);
	if (!map->map || parse_map(map->map, filename))
	{
		ft_free(map->map);
		return (1);
	}
	if (fill_diractions(&map->directions, filename))
	{
		ft_free(map->map);
		return (1);
	}
	if (fill_floor_ceiling(&map->flor, &map->ceiling, filename))
	{
		ft_free(map->map);
		return (1);
	}
	find_player_pose(map, &map->player_x, &map->player_y);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	if (argc != 2)
	{
		err("Invalid input\n");
		return (1);
	}
	map = malloc(sizeof(t_map));
	if (!map || parsing(argv[1], map) != 0)
	{
		free(map);
		return (1);
	}
	initialize(map);
	free(map);
	return (0);
}
