/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:03:51 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/11 17:04:03 by pnaessen         ###   ########lyon.fr   */
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
	new_node->prev = NULL;
	return (new_node);
}

void	add_back(t_stack **head, int value)
{
	t_stack	*node;
	t_stack	*last;

	node = new_node(value);
	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		node->prev = *head;
		node->next = *head;
		return ;
	}
	else
	{
		last = (*head)->prev;
		node->next = *head;
		node->prev = last;
		last->next = node;
		(*head)->prev = node;
	}
}

int	is_sorted(t_stack *stack)
{
	t_stack	*start;

	if (!stack)
		return (1);
	start = stack;
	while (stack->next != start)
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
	t_stack	*start;

	if (!stack)
		return (0);
	size = 1;
	start = stack;
	while (stack->next != start)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	t_stack	*start;

	if (!*stack)
		return ;
	start = *stack;
	current = *stack;
	while (1)
	{
		next = current->next;
		free(current);
		if (next == start)
			break ;
		current = next;
	}
	*stack = NULL;
}
