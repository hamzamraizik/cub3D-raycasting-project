/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:24:10 by hmraizik          #+#    #+#             */
/*   Updated: 2024/11/30 13:13:16 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_data_struct(t_data *data)
{
	if (data->map)
		ft_free(data->map->map);
	free(data->map);
	free(data);
}

void	move_player(t_data *data)
{
	double	move_step;
	double	new_p_x;
	double	new_p_y;

	data->player.rotation_angle += data->player.turn_dir * TURN_SPEED;
	move_step = data->player.walk_dir * WALK_SPEED;
	new_p_x = data->player.x + cos(data->player.rotation_angle) * move_step;
	new_p_y = data->player.y + sin(data->player.rotation_angle) * move_step;
	if (check_walls(new_p_x, new_p_y, data))
	{
		data->player.x = new_p_x;
		data->player.y = new_p_y;
	}
	new_p_x = data->player.x + cos(data->player.rotation_angle + M_PI / 2) * \
		data->player.sidemove;
	new_p_y = data->player.y + sin(data->player.rotation_angle + M_PI / 2) * \
		data->player.sidemove;
	if (check_walls(new_p_x, new_p_y, data))
	{
		data->player.x = new_p_x;
		data->player.y = new_p_y;
	}
}
