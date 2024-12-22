/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_n_hrz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:21:18 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/02 11:34:17 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

mlx_image_t	*get_horizontal_texture(t_data *data, int i, int x, int y)
{
	(void)x;
	(void)y;
	if (data->ray[i].is_ray_facing_up)
		return (data->texture->no_image_texture);
	return (data->texture->so_image_texture);
}

mlx_image_t	*get_vertical_texture(t_data *data, int i, int x, int y)
{
	(void)x;
	(void)y;
	if (data->ray[i].is_ray_facing_right)
		return (data->texture->we_image_texture);
	return (data->texture->ea_image_texture);
}

void	generate_3d_projection(t_data *data)
{
	int					i;
	t_line_y			line_y;
	mlx_image_t			*texture;
	t_wall_height_data	height_data;

	i = 0;
	while (i < NUM_OF_RAYS)
	{
		fill_sky_floor(data, i);
		data->ray[i].distance *= cos(data->player.rotation_angle \
								- data->ray[i].ray_angle);
		height_data.data = data;
		height_data.i = i;
		calculate_wall_height(&height_data);
		line_y.from = height_data.from_y;
		line_y.to = height_data.to_y;
		texture = find_text(data, i, 0, 0);
		sel_calculate_texture(data, i, texture);
		calculate_tex_pos(data, texture, \
						height_data.w_height, height_data.from_y);
		draw_text(line_y, texture, data, i);
		i++;
	}
}
