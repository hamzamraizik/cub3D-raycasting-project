/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:14:20 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:27:57 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	load_sprite_textures(t_data *cube)
{
	char	*str;
	char	*tmp2;
	char	*tmp1;
	int		i;

	i = 0;
	while (i < 180)
	{
		str = ft_strdup("./bonus/sprite/");
		tmp2 = ft_itoa(i + 1);
		tmp1 = str;
		str = ft_strjoinn(str, tmp2);
		free(tmp2);
		free(tmp1);
		tmp1 = str;
		str = ft_strjoinn(str, ".png");
		free(tmp1);
		cube->texture->s_sprite[i] = mlx_load_png(str);
		free(str);
		if (!cube->texture->s_sprite[i])
			printf("Error \nSprite txtur encountered an error at index %d\n", \
					i);
		i++;
	}
}

mlx_texture_t	*my_mlx_load_png(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		exit(err("loading texture\n"));
	return (texture);
}

mlx_image_t	*my_mlx_texture_to_image(void *mlx, mlx_texture_t *texture)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		err("image encountered\n");
	mlx_delete_texture(texture);
	return (image);
}

void	ft_texture_to_image(t_data *cube)
{
	cube->texture->no_image_texture = my_mlx_texture_to_image(cube->mlx_ptr, \
													cube->texture->no_texture);
	cube->texture->so_image_texture = my_mlx_texture_to_image(cube->mlx_ptr, \
													cube->texture->so_texture);
	cube->texture->we_image_texture = my_mlx_texture_to_image(cube->mlx_ptr, \
													cube->texture->we_texture);
	cube->texture->ea_image_texture = my_mlx_texture_to_image(cube->mlx_ptr, \
													cube->texture->ea_texture);
	cube->texture->door_image_texture = my_mlx_texture_to_image(cube->mlx_ptr, \
												cube->texture->door_texture);
}

void	load_textures(t_data *cube)
{
	cube->texture->no_texture = my_mlx_load_png(cube->map->directions.so);
	cube->texture->so_texture = my_mlx_load_png(cube->map->directions.no);
	cube->texture->we_texture = my_mlx_load_png(cube->map->directions.we);
	cube->texture->ea_texture = my_mlx_load_png(cube->map->directions.ea);
	cube->map->directions.door = "./bonus/door.png";
	cube->texture->door_texture = my_mlx_load_png(cube->map->directions.door);
	ft_texture_to_image(cube);
}
