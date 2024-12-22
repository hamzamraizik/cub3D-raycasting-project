/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:24:10 by hmraizik          #+#    #+#             */
/*   Updated: 2024/12/07 19:48:44 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	free_data_struct(t_data *data)
{
	if (data->map)
		ft_free(data->map->map);
	free(data->map);
	free(data);
}

int	rgb_to_hex2(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
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

uint32_t	find_color(t_data *data, int i, int j)
{
	uint32_t	tile_color;

	if (data->map->map[i][j] == 'D')
		tile_color = rgb_to_hex2(255, 255, 0);
	else if (data->map->map && data->map->map[i][j] == '1')
		tile_color = rgb_to_hex2(0, 0, 0);
	else
		tile_color = rgb_to_hex2(100, 100, 100);
	return (tile_color);
}

void	draw_tile(t_data *data, int tileX, int tileY, uint32_t tile_color)
{
	int	x;
	int	y;
	int	scaled_size;

	scaled_size = TILE_SIZE * MINIMAP_SCALE_FACTOR;
	x = -1;
	while (++x < scaled_size)
	{
		y = -1;
		while (++y < scaled_size)
		{
			if (tileX + x >= 0 && tileX + x < data->num_of_cols * TILE_SIZE && \
				tileY + y >= 0 && tileY + y < data->num_of_rows * TILE_SIZE)
			{
				put_pixel_safe(data->img_ptr, tileX + x, tileY + y, tile_color);
			}
		}
	}
}
