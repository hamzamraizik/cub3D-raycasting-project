/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:58:49 by hmraizik          #+#    #+#             */
/*   Updated: 2024/12/05 11:00:09 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	close_game(t_data *data)
{
	mlx_close_window(data->mlx_ptr);
	free_data_struct(data);
	exit(0);
}

int	rows_length(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	err(char *str)
{
	write(2, "Error\n", 7);
	return (write(2, str, ft_strlen(str)));
}
