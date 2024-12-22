/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:17:05 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/01 21:46:00 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	draw_text(t_line_y line_y, mlx_image_t *cur_tex, t_data *cube, long x)
{
	int	i;

	i = line_y.from;
	while (i < line_y.to)
	{
		cube->texture->text_y = (int)cube->texture->text_pos % cur_tex->height;
		cube->ray[x].color = get_texture_pixel(cur_tex, \
		cube->texture->text_x, cube->texture->text_y);
		put_pixel_safe(cube->img_ptr, x, i, cube->ray[x].color);
		cube->texture->text_pos += cube->texture->step;
		i++;
	}
}

int	rgb_to_hex(t_colors color)
{
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 255);
}

void	fill_sky_floor(t_data *data, int i)
{
	int	j;

	j = 0;
	while (j < SCREEN_HEIGTH / 2)
	{
		put_pixel_safe(data->img_ptr, i, j, rgb_to_hex(data->map->flor));
		j++;
	}
	j = SCREEN_HEIGTH / 2;
	while (j < SCREEN_HEIGTH)
	{
		put_pixel_safe(data->img_ptr, i, j, rgb_to_hex(data->map->ceiling));
		j++;
	}
}

void	calculate_wall_height(t_wall_height_data *h_data)
{
	double	base_distance;
	int		wall_strip_height;

	base_distance = (SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2);
	h_data->w_height = (TILE_SIZE \
							/ h_data->data->ray[h_data->i].distance) \
							* base_distance;
	wall_strip_height = (int)h_data->w_height;
	h_data->from_y = (SCREEN_HEIGTH / 2) - (wall_strip_height / 2);
	if (h_data->from_y < 0)
		h_data->from_y = 0;
	h_data->to_y = (SCREEN_HEIGTH / 2) + (wall_strip_height / 2);
	if (h_data->to_y > SCREEN_HEIGTH)
		h_data->to_y = SCREEN_HEIGTH;
}

void	ft_animation(t_data *cub)
{
	static int	i;

	if (!cub || !cub->mlx_ptr || !cub->texture || !cub->texture->s_sprite[0])
		return ;
	if (cub->texture->fram < 0 || cub->texture->fram >= MAX_FRAMES)
		cub->texture->fram = 0;
	if (i % 2 == 0)
	{
		if (cub->texture->tp)
			mlx_delete_image(cub->mlx_ptr, cub->texture->tp);
		cub->texture->tp = mlx_texture_to_image(cub->mlx_ptr, \
								cub->texture->s_sprite[cub->texture->fram]);
		if (!cub->texture->tp)
			return ;
		mlx_resize_image(cub->texture->tp, SCREEN_WIDTH, SCREEN_HEIGTH);
		mlx_image_to_window(cub->mlx_ptr, cub->texture->tp, 0, 0);
		if (!cub->texture->animt)
			cub->texture->fram = 0;
		if (cub->texture->animt && cub->texture->fram == 99)
			1 && (cub->texture->fram = 0, cub->texture->animt = 0);
		cub->texture->fram++;
	}
	i++;
}
