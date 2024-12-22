/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:02:33 by hmraizik          #+#    #+#             */
/*   Updated: 2024/12/01 21:55:38 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	render(t_data *data)
{
	generate_3d_projection(data);
	render_mini_map(data);
	render_player(data);
}

void	update(t_data *data)
{
	move_player(data);
	castallrays(data);
}

void	update_and_render(void *void_data)
{
	t_data	*data;

	data = (t_data *)void_data;
	ft_close_door(data, 0, 0);
	update(data);
	render(data);
	ft_animation(data);
}
