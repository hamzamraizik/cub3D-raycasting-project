/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_rays_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:04:50 by hmraizik          #+#    #+#             */
/*   Updated: 2024/12/07 19:25:49 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

double	normaliz(double angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

void	increment_vert_steps(t_data *data, int strip_id)
{
	double	x_to_check;
	double	y_to_check;
	double	next_v_touch_x;
	double	next_v_touch_y;

	next_v_touch_x = data->ray[strip_id].xintercept;
	next_v_touch_y = data->ray[strip_id].yintercept;
	while (next_v_touch_x >= 0 && next_v_touch_x < SCREEN_WIDTH
		&& next_v_touch_y >= 0 && next_v_touch_y < SCREEN_HEIGTH)
	{
		if (data->ray[strip_id].is_ray_facing_left)
			x_to_check = next_v_touch_x - 1;
		else
			x_to_check = next_v_touch_x;
		y_to_check = next_v_touch_y;
		if (is_wall(x_to_check, y_to_check, data))
		{
			data->ray[strip_id].vert_wall_hit_x = next_v_touch_x;
			data->ray[strip_id].vert_wall_hit_y = next_v_touch_y;
			data->ray[strip_id].found_vert_wall_hit = 1;
			break ;
		}
		next_v_touch_x += data->ray[strip_id].xstep;
		next_v_touch_y += data->ray[strip_id].ystep;
	}
}

void	verticaltay(t_data *data, double rayangle, int strip_id)
{
	data->ray[strip_id].found_vert_wall_hit = 0;
	data->ray[strip_id].xintercept = floor(data->player.x / TILE_SIZE) \
		* TILE_SIZE;
	if (data->ray[strip_id].is_ray_facing_right)
		data->ray[strip_id].xintercept += TILE_SIZE;
	data->ray[strip_id].yintercept = data->player.y \
	+ (data->ray[strip_id].xintercept - data->player.x) * tan(rayangle);
	data->ray[strip_id].xstep = TILE_SIZE;
	if (data->ray[strip_id].is_ray_facing_left)
		data->ray[strip_id].xstep *= -1;
	data->ray[strip_id].ystep = TILE_SIZE * tan(rayangle);
	if (data->ray[strip_id].is_ray_facing_up && data->ray[strip_id].ystep > 0)
		data->ray[strip_id].ystep *= -1;
	if (data->ray[strip_id].is_ray_facing_down && data->ray[strip_id].ystep < 0)
		data->ray[strip_id].ystep *= -1;
	increment_vert_steps(data, strip_id);
}

void	increment_horiz_steps(t_data *data, int strip_id)
{
	double	next_h_touch_x;
	double	next_h_touch_y;
	double	x_to_check;
	double	y_to_check;

	next_h_touch_x = data->ray[strip_id].xintercept;
	next_h_touch_y = data->ray[strip_id].yintercept;
	while (next_h_touch_x >= 0 && next_h_touch_x < SCREEN_WIDTH
		&& next_h_touch_y >= 0 && next_h_touch_y < SCREEN_HEIGTH)
	{
		x_to_check = next_h_touch_x;
		if (data->ray[strip_id].is_ray_facing_up)
			y_to_check = next_h_touch_y - 1;
		else
			y_to_check = next_h_touch_y;
		if (is_wall(x_to_check, y_to_check, data))
		{
			data->ray[strip_id].horz_wall_hit_x = next_h_touch_x;
			data->ray[strip_id].horz_wall_hit_y = next_h_touch_y;
			data->ray[strip_id].found_horz_wall_hit = 1;
			break ;
		}
		next_h_touch_x += data->ray[strip_id].xstep;
		next_h_touch_y += data->ray[strip_id].ystep;
	}
}

void	horizontalray(t_data *data, double rayangle, int strip_id)
{
	data->ray[strip_id].found_horz_wall_hit = 0;
	data->ray[strip_id].yintercept = \
	floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (data->ray[strip_id].is_ray_facing_down)
		data->ray[strip_id].yintercept += TILE_SIZE;
	data->ray[strip_id].xintercept = data->player.x + \
		(data->ray[strip_id].yintercept - data->player.y) / tan(rayangle);
	data->ray[strip_id].ystep = TILE_SIZE;
	if (data->ray[strip_id].is_ray_facing_up)
		data->ray[strip_id].ystep *= -1;
	data->ray[strip_id].xstep = TILE_SIZE / tan(rayangle);
	if (data->ray[strip_id].is_ray_facing_left && data->ray[strip_id].xstep > 0)
		data->ray[strip_id].xstep *= -1;
	if (data->ray[strip_id].is_ray_facing_right \
	&& data->ray[strip_id].xstep < 0)
		data->ray[strip_id].xstep *= -1;
	increment_horiz_steps(data, strip_id);
}
