/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:41:14 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:05:31 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	str = strtrim(str);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' \
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f' \
			|| str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (!isdigit(str[i]) && str[i] != '\0')
		return (-1);
	free(str);
	return (res * sign);
}

int	is_digit_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!isdigit(line[i]) && !is_whitespace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_floor_line(char *line)
{
	return (ft_strncmp(line, "F", 1) == 0);
}

int	is_ceiling_line(char *line)
{
	return (ft_strncmp(line, "C", 1) == 0);
}

int	is_avalidckaracter(char *line)
{
	int	i;

	i = 0;
	if (line[0] == ' ')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != '1')
		{
			err("Invalid character\n");
			return (1);
		}
		return (0);
	}
	if (line[0] != '\n' && line[0] != '1' \
		&& line[0] != '0' && line[0] != 'N' \
		&& line[0] != 'W' && line[0] != 'E' && line[0] != 'C' \
		&& line[0] != 'F' && line[0] != '\0')
	{
		err("Invalid character\n");
		return (1);
	}
	return (0);
}
