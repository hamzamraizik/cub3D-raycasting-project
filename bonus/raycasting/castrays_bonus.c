/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:10:29 by hmraizik          #+#    #+#             */
/*   Updated: 2024/12/01 21:55:30 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	set_distance(t_data *data, double horz_hit_distance, \
	double vert_hit_distance, int strip_id)
{
	if (vert_hit_distance < horz_hit_distance)
	{
		data->ray[strip_id].distance = vert_hit_distance;
		data->ray[strip_id].wall_hit_x = data->ray[strip_id].vert_wall_hit_x;
		data->ray[strip_id].wall_hit_y = data->ray[strip_id].vert_wall_hit_y;
		data->ray[strip_id].was_hit_vertical = 1;
	}
	else
	{
		data->ray[strip_id].distance = horz_hit_distance;
		data->ray[strip_id].wall_hit_x = data->ray[strip_id].horz_wall_hit_x;
		data->ray[strip_id].wall_hit_y = data->ray[strip_id].horz_wall_hit_y;
		data->ray[strip_id].was_hit_vertical = 0;
	}
}

void	dist_calculn(t_data *data, double rayangle, int strip_id)
{
	double	horz_hit_distance;
	double	vert_hit_distance;

	if (data->ray[strip_id].found_horz_wall_hit)
		horz_hit_distance = distance(data->player.x, data->player.y, \
				data->ray[strip_id].horz_wall_hit_x, \
				data->ray[strip_id].horz_wall_hit_y);
	else
		horz_hit_distance = INT_MAX;
	if (data->ray[strip_id].found_vert_wall_hit)
		vert_hit_distance = distance(data->player.x, data->player.y,
				data->ray[strip_id].vert_wall_hit_x, \
				data->ray[strip_id].vert_wall_hit_y);
	else
		vert_hit_distance = INT_MAX;
	set_distance(data, horz_hit_distance, vert_hit_distance, strip_id);
	data->ray[strip_id].ray_angle = rayangle;
}

void	castray(double rayangle, t_data *data, int strip_id)
{
	rayangle = normaliz(rayangle);
	checkrayfacing(rayangle, data, strip_id);
	horizontalray(data, rayangle, strip_id);
	verticaltay(data, rayangle, strip_id);
	dist_calculn(data, rayangle, strip_id);
}

int	castallrays(t_data *data)
{
	double	ray_angle;
	int		strip_id;

	ray_angle = data->player.rotation_angle - (FOV_ANGLE / 2);
	strip_id = 0;
	while (strip_id < NUM_OF_RAYS)
	{
		castray(ray_angle, data, strip_id);
		ray_angle += FOV_ANGLE / NUM_OF_RAYS;
		strip_id++;
	}
	return (0);
}
