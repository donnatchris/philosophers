/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:05 by christophed       #+#    #+#             */
/*   Updated: 2025/01/25 18:50:01 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dclst.h"

// Function to find the position of a node in the doubly circular linked list
// Returns the position of the node in the list
// or -1 if the node is not in the list
int	dclst_find_node_pos(t_dclst *head, t_dclst *node)
{
	t_dclst	*current;
	int		position;

	if (!head || !node)
		return (-1);
	current = head;
	position = 0;
	while (current != node)
	{
		position++;
		current = current->next;
		if (current == head)
			return (-1);
	}
	return (position);
}

// Function to find a node by its position in the doubly circular linked list
t_dclst	*dclst_find_node_with_pos(t_dclst *head, int position)
{
	t_dclst	*current;
	int		i;

	if (!head)
		return (NULL);
	current = head;
	i = 0;
	while (i < position)
	{
		current = current->next;
		i++;
	}
	return (current);
}
