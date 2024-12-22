/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:58:49 by hmraizik          #+#    #+#             */
/*   Updated: 2024/12/07 14:35:41 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	close_game(t_data *data)
{
	mlx_close_window(data->mlx_ptr);
	free_data_struct(data);
	exit(0);
}

void	ft_open_door(t_data *data, int i)
{
	int		j;
	double	dist_x;
	double	dist_y;
	double	dist;

	i = -1;
	while (++i < data->num_of_rows)
	{
		j = -1;
		while (++j < data->num_of_cols)
		{
			if (data->map->map[i][j] == 'D')
			{
				dist_x = j * TILE_SIZE + TILE_SIZE / 2 - data->ray->wall_hit_x;
				dist_y = i * TILE_SIZE + TILE_SIZE / 2 - data->ray->wall_hit_y;
				dist = sqrt(dist_x * dist_x + dist_y * dist_y);
				if (dist < TILE_SIZE * 3)
				{
					1 && (data->map->map[i][j] = 'x', \
							data->door_open_timer = 100);
					return ;
				}
			}
		}
	}
}

int	rows_length(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	err(char *str)
{
	write(2, "Error\n", 7);
	return (write(2, str, ft_strlen(str)));
}
