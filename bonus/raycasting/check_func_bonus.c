/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:29:33 by hmraizik          #+#    #+#             */
/*   Updated: 2024/12/01 21:55:34 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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
	return (p->map->map[mapy][mapx] == '1' || p->map->map[mapy][mapx] == 'D');
}

bool	check_walls(double x, double y, t_data *cube)
{
	if (!is_wall(x + 3, y + 3, cube) && !is_wall(x - 3, y + 3, cube)
		&& !is_wall(x + 3, y - 3, cube) && !is_wall(x - 3, y - 3, cube))
		return (true);
	return (false);
}

bool	is_player_near_door(t_data *data, int door_x, int door_y)
{
	double	door_center_x;
	double	door_center_y;
	double	dist_x;
	double	dist_y;
	double	distance;

	door_center_x = door_x * TILE_SIZE + TILE_SIZE / 2;
	door_center_y = door_y * TILE_SIZE + TILE_SIZE / 2;
	dist_x = data->player.x - door_center_x;
	dist_y = data->player.y - door_center_y;
	distance = sqrt(dist_x * dist_x + dist_y * dist_y);
	return (distance < TILE_SIZE);
}
