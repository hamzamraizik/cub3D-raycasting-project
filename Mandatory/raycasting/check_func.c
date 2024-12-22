/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:29:33 by hmraizik          #+#    #+#             */
/*   Updated: 2024/11/30 12:55:39 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	checkrayfacing(double rayangle, t_data *data, int strip_id)
{
	data->ray[strip_id].is_ray_facing_down = rayangle > 0 && rayangle < PI;
	data->ray[strip_id].is_ray_facing_up = \
	!data->ray[strip_id].is_ray_facing_down;
	data->ray[strip_id].is_ray_facing_right = \
	rayangle < 0.5 * PI || rayangle > 1.5 * PI;
	data->ray[strip_id].is_ray_facing_left = \
	!data->ray[strip_id].is_ray_facing_right;
}

int	is_wall(double x, double y, t_data *p)
{
	int	mapx;
	int	mapy;

	if (x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGTH)
		return (1);
	mapx = floor(x / TILE_SIZE);
	mapy = floor(y / TILE_SIZE);
	if (mapy < 0 || mapy >= p->num_of_rows || mapx < 0 || mapx >= p->num_of_cols
		|| p->map == NULL || p->map->map == NULL || p->map->map[mapy] == NULL
		|| mapx >= (int)ft_strlen(p->map->map[mapy]))
		return (1);
	return (p->map->map[mapy][mapx] == '1');
}

bool	check_walls(double x, double y, t_data *cube)
{
	if (!is_wall(x + 3, y + 3, cube) && !is_wall(x - 3, y + 3, cube)
		&& !is_wall(x + 3, y - 3, cube) && !is_wall(x - 3, y - 3, cube))
		return (true);
	return (false);
}
