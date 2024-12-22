/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:18:21 by mlimami           #+#    #+#             */
/*   Updated: 2024/11/28 05:31:31 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = malloc((ft_strlen(left_str) + ft_strlen(buff) + 1));
	if (str == NULL)
		return (free(left_str), left_str = NULL, NULL);
	i = 0;
	j = 0;
	while (left_str[i] != '\0')
	{
		str[i] = left_str[i];
		i++;
	}
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(left_str);
	left_str = NULL;
	return (str);
}

char	*ft_cut_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (left_str[i] == '\n')
		i++;
	str = malloc((i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*left_from_cut(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (left_str[i] == '\n')
		i++;
	if (left_str[i] == '\0')
		return (free(left_str), left_str = NULL, NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (free(left_str), left_str = NULL, NULL);
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}
