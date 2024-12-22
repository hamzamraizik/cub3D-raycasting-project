/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:04:59 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/01 21:10:44 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	ft_countword(char const *str, char c)
{
	int	i;
	int	count;
	int	b;

	i = 0;
	count = 0;
	b = 0;
	while (str[i])
	{
		if (str[i] != c && b == 0)
		{
			b = 1;
			count++;
		}
		else if (str[i] == c)
			b = 0;
		i++;
	}
	if (str[i] == '\0' && str[i - 2] == c)
	{
		return (count - 1);
	}
	return (count);
}

void	ft_free_split(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	*substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	int		wi;
	int		i;
	int		wl;
	char	**words;

	wi = 0;
	wc = ft_countword(s, c);
	words = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (wi < wc)
	{
		while (s[i] == c)
			i++;
		wl = 0;
		while (s[i + wl] && s[i + wl] != c)
			wl++;
		words[wi] = substr(s, i, wl);
		if (!words[wi++])
			return (ft_free_split(words), NULL);
		i += wl;
	}
	return (words[wi] = NULL, words);
}
