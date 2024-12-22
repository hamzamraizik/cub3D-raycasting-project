/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diractions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:49:45 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/07 16:15:07 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	is_valid(char *filename)
{
	char	**map;

	map = fillmap(filename);
	if (!map)
		return (ft_free(map), 1);
	if (check_directions(map))
		return (1);
	if (validate_flor_and_ceiling(map))
		return (1);
	return (0);
}

int	check_first_and_last_walls(char **line, char *filename)
{
	int	i;
	int	len;

	i = 0;
	len = map_clms(filename);
	while (line[0][i])
	{
		if (line[0][i] != '1' && line[0][i] != ' ')
		{
			err("Invalid first map line\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (line[len - 1][i])
	{
		if (line[len - 1][i] != '1' && line[len - 1][i] != ' ')
		{
			err("Invalid last map line\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	if_all_are_exist(int nf, int sf, int wf, int ef)
{
	if (!nf || !sf || !wf || !ef)
	{
		err("Missing direction\n");
		return (1);
	}
	return (0);
}

int	check_directions(char **map)
{
	int	i;
	int	sf;
	int	nf;
	int	wf;
	int	ef;

	1 && (i = -1, sf = 0, nf = 0, wf = 0, ef = 0);
	while (map[++i])
	{
		if (!ft_strncmp(map[i], "NO ", 3) || !ft_strncmp(map[i], "NO", 2))
			no_check(map[i], &nf);
		else if (!ft_strncmp(map[i], "SO ", 3) || !ft_strncmp(map[i], "SO", 2))
			so_check(map[i], &sf);
		else if (!ft_strncmp(map[i], "WE ", 3) || !ft_strncmp(map[i], "WE", 2))
			we_check(map[i], &wf);
		else if (!ft_strncmp(map[i], "EA ", 3) || !ft_strncmp(map[i], "EA", 2))
			ea_check(map[i], &ef);
		else if (is_avalidckaracter(map[i]))
			return (1);
		else if (is_itmap(map[i]) && (!nf || !sf || !wf || !ef))
			return (err("Missing direction\n"), 1);
	}
	return (if_all_are_exist(nf, sf, wf, ef));
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}
