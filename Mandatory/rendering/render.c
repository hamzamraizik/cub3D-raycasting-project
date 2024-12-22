/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:44:39 by mlimami           #+#    #+#             */
/*   Updated: 2024/11/27 09:12:26 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

mlx_image_t	*find_text(t_data *data, int i, int x, int y)
{
	mlx_image_t	*txt;

	if (!data->ray[i].was_hit_vertical)
	{
		x = data->ray[i].horz_wall_hit_x;
		y = data->ray[i].horz_wall_hit_y;
		txt = get_horizontal_texture(data, i, x, y);
	}
	else
	{
		x = data->ray[i].vert_wall_hit_x;
		y = data->ray[i].vert_wall_hit_y;
		txt = get_vertical_texture(data, i, x, y);
	}
	return (txt);
}

void	sel_calculate_texture(t_data *data, int index, mlx_image_t *cur_texture)
{
	if (!data->ray[index].was_hit_vertical)
		data->texture->text_x = (int)(data->ray[index].wall_hit_x \
			* cur_texture->width \
			/ TILE_SIZE) % cur_texture->width;
	else
		data->texture->text_x = (int)(data->ray[index].wall_hit_y \
			* cur_texture->width \
			/ TILE_SIZE) % cur_texture->width;
}

void	calculate_tex_pos(t_data *cube, mlx_image_t *tex, double w_h, int f_y)
{
	if (w_h > 0)
		cube->texture->step = (double) tex->height / w_h;
	else
		cube->texture->step = 0;
	cube->texture->text_pos = (f_y - (SCREEN_HEIGTH / 2 - w_h / 2)) \
									* cube->texture->step;
}

uint32_t	get_texture_pixel(mlx_image_t *texture, int x, int y)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	int		index;

	if (!texture)
		return (0x000000);
	if (x >= 0 && (uint32_t)x < texture->width
		&& y >= 0 && (uint32_t)y < texture->height)
	{
		index = (y * texture->width + x) * 4;
		r = texture->pixels[index];
		g = texture->pixels[index + 1];
		b = texture->pixels[index + 2];
		a = texture->pixels[index + 3];
		return (r << 24 | g << 16 | b << 8 | a);
	}
	return (0x000000);
}

void	put_pixel_safe(mlx_image_t *img, long x, long y, long color)
{
	if ((x < 0 || x >= SCREEN_WIDTH) || (y < 0 || y >= SCREEN_HEIGTH))
		return ;
	mlx_put_pixel(img, x, y, color);
}
