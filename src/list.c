/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:03:51 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/09 09:04:25 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->next = NULL;
	return (new_node);
}

void	add_back(t_stack **head, int value)
{
	t_stack	*node;
	t_stack	*temp;

	node = new_node(value);
	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	temp = stack;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	get_position(t_stack *stack, int value)
{
	int		position;
	t_stack	*current;

	position = 0;
	current = stack;
	while (current)
	{
		if (current->data == value)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}
