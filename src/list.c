/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:03:51 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/26 19:10:31 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_node(int value)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->next = NULL;
	return (new_node);
}

void add_back(t_stack **head, int value)
{
	t_stack *node;
	t_stack *temp;

	node = new_node(value);
	if (!node)
		return;
	if (!*head)
	{
		*head = node;
		return;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}
