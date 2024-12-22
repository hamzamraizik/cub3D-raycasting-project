/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:50:21 by hmraizik          #+#    #+#             */
/*   Updated: 2024/12/01 21:55:42 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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
	if (keydata.key == MLX_KEY_M)
		ft_open_door(data, 0);
	mlx_keys_release(keydata, data);
	handle_key_release(keydata, data);
}

void	handle_key_release(mlx_key_data_t keydata, t_data *cube)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == 32)
			cube->cursor_hidden = 1;
		else if (keydata.key == 66)
			cube->cursor_hidden = 0;
	}
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
	if (keydata.key == MLX_KEY_R)
		1 && ((!data->texture->animt) && (data->texture->fram = 0),
			data->texture->animt = 1);
}

void	ft_mouse(double xpos, double ypos, void *param)
{
	t_data	*cub;

	(void)ypos;
	cub = (t_data *)param;
	mlx_set_cursor_mode(cub->mlx_ptr, MLX_MOUSE_HIDDEN);
	if (cub->cursor_hidden == 1)
		mlx_set_mouse_pos(cub->mlx_ptr, SCREEN_WIDTH / 2, SCREEN_HEIGTH / 2);
	if (cub->cursor_hidden && SCREEN_WIDTH / 2 > xpos)
		cub->player.rotation_angle -= fabs(SCREEN_WIDTH / 2 - xpos) * 0.0009;
	else if (cub->cursor_hidden && SCREEN_WIDTH / 2 < xpos)
		cub->player.rotation_angle += fabs(SCREEN_WIDTH / 2 - xpos) * 0.0009;
}
