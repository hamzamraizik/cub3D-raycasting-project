/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlimami <mlimami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 06:02:17 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/05 11:04:59 by mlimami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	*gc_malloc(size_t size)
{
	static t_gc_node	*gc_head = NULL;
	t_gc_node			*new_node;

	new_node = malloc(sizeof(t_gc_node) + size);
	if (!new_node)
	{
		err("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->next = gc_head;
	gc_head = new_node;
	return ((void *)(new_node + 1));
}

void	gc_free_all(void)
{
	static t_gc_node	*gc_head = NULL;
	t_gc_node			*current;
	t_gc_node			*temp;

	current = gc_head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	gc_head = NULL;
}
