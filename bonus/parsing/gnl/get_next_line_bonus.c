/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:15:04 by mlimami           #+#    #+#             */
/*   Updated: 2024/11/30 18:19:32 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	lent;
	char	*dest;

	i = 0;
	lent = ft_strlen(src);
	dest = (char *)malloc(lent + 1);
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

char	*ft_read_str(int fd, char *left_str)
{
	char	*buffer;
	int		read_return;
	char	*newline;

	read_return = 1;
	newline = NULL;
	buffer = malloc(((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (free(left_str), left_str = NULL, NULL);
	if (!left_str)
		left_str = ft_strdup("");
	while (!newline && read_return > 0)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1 || !left_str)
			break ;
		buffer[read_return] = '\0';
		left_str = ft_strjoin(left_str, buffer);
		if (!left_str)
			break ;
		newline = ft_strchr(left_str, '\n');
	}
	free(buffer);
	buffer = NULL;
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str = NULL;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
	{
		free(left_str);
		left_str = NULL;
		return (NULL);
	}
	left_str = ft_read_str(fd, left_str);
	if (!left_str)
		return (NULL);
	if (!*left_str)
		return (free(left_str), left_str = NULL, NULL);
	line = ft_cut_line(left_str);
	if (!line)
		return (NULL);
	left_str = left_from_cut(left_str);
	return (line);
}
