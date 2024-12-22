/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:02:33 by hmraizik          #+#    #+#             */
/*   Updated: 2024/12/07 19:48:02 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render(t_data *data)
{
	generate_3d_projection(data);
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
	update(data);
	render(data);
}
