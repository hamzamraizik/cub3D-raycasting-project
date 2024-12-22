/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:13:37 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:05:44 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	no_check(char *line, int *nf)
{
	if (*nf)
	{
		err("Duplicate NO line\n");
		return (1);
	}
	if (is_valid_direction(line))
	{
		*nf = 1;
		return (0);
	}
	return (1);
}

int	so_check(char *line, int *sf)
{
	if (*sf)
	{
		err("Duplicate SO line\n");
		return (1);
	}
	if (is_valid_direction(line))
	{
		*sf = 1;
		return (0);
	}
	return (1);
}

int	we_check(char *line, int *wf)
{
	if (*wf)
	{
		err("Duplicate WE line\n");
		return (1);
	}
	if (is_valid_direction(line))
	{
		*wf = 1;
		return (0);
	}
	return (1);
}

int	ea_check(char *line, int *ef)
{
	if (*ef)
	{
		err("Duplicate EA line\n");
		return (1);
	}
	if (is_valid_direction(line))
	{
		*ef = 1;
		return (0);
	}
	return (1);
}
