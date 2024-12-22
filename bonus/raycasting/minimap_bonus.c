/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:02:22 by hmraizik          #+#    #+#             */
/*   Updated: 2024/12/02 14:11:43 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	draw_mini_circle(t_data *data, double x, double y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 300)
	{
		j = -1;
		while (++j < 300)
		{
			if (sqrt(pow(j - x, 2) + pow(i - y, 2)) <= 5)
				put_pixel_safe(data->img_ptr, j, i, color);
		}
	}
}

void	render_player(t_data *data)
{
	int	middle_x;
	int	middle_y;
	int	map_x;
	int	map_y;

	middle_x = MINIMAP_WIDTH / 2;
	middle_y = MINIMAP_HEIGHT / 2;
	map_x = (int)(data->player.x / TILE_SIZE);
	map_y = (int)(data->player.y / TILE_SIZE);
	if (map_x >= 0 && map_x < data->num_of_cols && \
		map_y >= 0 && map_y < data->num_of_rows && \
		data->map->map[map_y][map_x] == '0')
	{
		draw_mini_circle(data, middle_x, middle_y, rgb_to_hex2(255, 0, 0));
	}
}

void	draw_minimap_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_WIDTH)
	{
		j = 0;
		while (j < MINIMAP_HEIGHT)
		{
			put_pixel_safe(data->img_ptr, i, j, rgb_to_hex2(100, 100, 100));
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_data *data, int start_x, int start_y)
{
	int			x;
	int			y;
	uint32_t	color;
	int			map_x;
	int			map_y;

	y = -1;
	while (++y < MINIMAP_HEIGHT / TILE_SIZE)
	{
		x = -1;
		while (++x < MINIMAP_WIDTH / TILE_SIZE)
		{
			map_x = start_x + x;
			map_y = start_y + y;
			if (map_x >= 0 && map_x < data->num_of_cols && \
				map_y >= 0 && map_y < data->num_of_rows)
			{
				color = find_color(data, map_y, map_x);
				draw_tile(data, x * TILE_SIZE, y * TILE_SIZE, color);
			}
		}
	}
}

void	render_mini_map(t_data *data)
{
	int			start_x;
	int			start_y;

	draw_mini_circle(data, MINIMAP_WIDTH / 2, MINIMAP_HEIGHT / 2, \
	rgb_to_hex2(255, 0, 0));
	start_x = (int)(data->player.x / TILE_SIZE) - (MINIMAP_WIDTH / \
	(2 * TILE_SIZE));
	start_y = (int)(data->player.y / TILE_SIZE) - (MINIMAP_HEIGHT / \
	(2 * TILE_SIZE));
	draw_minimap_background(data);
	draw_minimap(data, start_x, start_y);
	draw_mini_circle(data, MINIMAP_WIDTH / 2, MINIMAP_HEIGHT / 2, \
	rgb_to_hex2(255, 0, 0));
}
