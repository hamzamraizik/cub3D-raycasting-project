/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 06:00:02 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:03:28 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init(SCREEN_WIDTH, SCREEN_HEIGTH, "cub3D", 0);
	if (!data->mlx_ptr)
		return (err("initializing MLX.\n"));
	data->img_ptr = mlx_new_image(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGTH);
	if (!data->img_ptr)
	{
		mlx_close_window(data->mlx_ptr);
		return (err("creating MLX image.\n"));
	}
	mlx_image_to_window(data->mlx_ptr, data->img_ptr, 0, 0);
	return (0);
}

void	setup(t_data *data)
{
	data->player.x = data->map->player_x * TILE_SIZE + (TILE_SIZE / 2);
	data->player.y = data->map->player_y * TILE_SIZE + (TILE_SIZE / 2);
	data->num_of_cols = ft_strlen(data->map->map[0]);
	data->num_of_rows = rows_length(data->map->map);
	data->player.turn_dir = 0;
	data->player.walk_dir = 0;
	data->player.rotation_angle = data->map->p_direction;
}

void	ft_close_door(t_data *data, int i, int j)
{
	if (data->door_open_timer > 0)
	{
		data->door_open_timer--;
		return ;
	}
	i = -1;
	while (++i < data->num_of_rows)
	{
		j = 0;
		while (j < data->num_of_cols)
		{
			if (data->map->map[i][j] == 'x')
			{
				if (is_player_near_door(data, j, i))
				{
					data->door_open_timer = 30;
					return ;
				}
				data->map->map[i][j] = 'D';
				return ;
			}
			j++;
		}
	}
}

int	data_allocation(t_data **data, t_map *map)
{
	(*data) = malloc(sizeof(t_data));
	if (!(*data))
		return (ft_free(map->map), free(map), \
				err("Memory allocation failed\n"), 1);
	(*data)->map = gc_malloc(sizeof(t_map));
	if (!(*data)->map)
		return (free(*data), ft_free(map->map), free(map), \
				err("Memory allocation failed\n"), 1);
	if (map->map)
		(*data)->map = map;
	if (!(*data)->map->map)
		return (err("map is NULL\n"), 1);
	return (0);
}

int	initialize(t_map *map)
{
	t_data	*data;

	data = NULL;
	if (data_allocation(&data, map))
		return (1);
	if (init_window(data))
		return (free_data_struct(data), gc_free_all(), 1);
	setup(data);
	data->texture = gc_malloc(sizeof(t_texture));
	if (!data->texture)
	{
		return (free_data_struct(data), gc_free_all(), \
			ft_free(map->map), free(map), \
			err("Memory allocation failed\n"));
	}
	load_textures(data);
	load_sprite_textures(data);
	mlx_key_hook(data->mlx_ptr, process_keys, data);
	mlx_loop_hook(data->mlx_ptr, update_and_render, data);
	mlx_cursor_hook(data->mlx_ptr, ft_mouse, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
