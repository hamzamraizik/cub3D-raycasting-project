/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:50:21 by hmraizik          #+#    #+#             */
/*   Updated: 2024/11/30 13:30:45 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	process_keys(struct mlx_key_data keydata, void *void_data)
{
	t_data	*data;

	data = (t_data *)void_data;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_game(data);
	if (keydata.key == MLX_KEY_W)
		data->player.walk_dir = 1;
	if (keydata.key == MLX_KEY_S)
		data->player.walk_dir = -1;
	if (keydata.key == MLX_KEY_RIGHT)
		data->player.turn_dir = 1;
	if (keydata.key == MLX_KEY_LEFT)
		data->player.turn_dir = -1;
	if (keydata.key == MLX_KEY_D)
		data->player.sidemove = 1;
	if (keydata.key == MLX_KEY_A)
		data->player.sidemove = -1;
	mlx_keys_release(keydata, data);
}

void	mlx_keys_release(struct mlx_key_data keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		data->player.walk_dir = 0;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		data->player.walk_dir = 0;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		data->player.turn_dir = 0;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		data->player.turn_dir = 0;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D) && \
		keydata.action == MLX_RELEASE)
		data->player.sidemove = 0;
}
