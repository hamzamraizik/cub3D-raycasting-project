/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:49:12 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/07 16:39:10 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strdupp(char *src)
{
	size_t	i;
	size_t	lent;
	char	*dest;

	i = 0;
	lent = ft_strlen(src);
	dest = (char *)gc_malloc(lent + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*gc_and_cpy(char *src)
{
	char	*dest;

	dest = gc_malloc(ft_strlen(src) + 1);
	ft_strcpy(dest, src);
	return (dest);
}

void	pad_map_lines(char **map, size_t largest_line)
{
	int		i;
	char	*padded_line;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) < largest_line)
		{
			padded_line = pad_line_with_spaces(map[i], largest_line);
			free(map[i]);
			map[i] = padded_line;
		}
		i++;
	}
}
