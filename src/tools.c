/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:10:42 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/05 14:39:22 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack && stack->next)
	{
		temp = stack->data;
		stack->data = stack->next->data;
		stack->next->data = temp;
	}
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	push_to(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (*src)
	{
		temp = *src;
		*src = (*src)->next;
		temp->next = *dest;
		*dest = temp;
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = temp;
	}
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
