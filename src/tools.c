/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:10:42 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/01 16:43:53 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack) // sa, sb
{
	int	temp;

	if (stack && stack->next)
	{
		temp = stack->data;
		stack->data = stack->next->data;
		stack->next->data = temp;
	}
}

void	swap_both(t_stack *a, t_stack *b) // ss
{
	swap(a);
	swap(b);
}

void	push_to(t_stack **src, t_stack **dest) // pa, pb
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

void	rotate(t_stack **stack) // ra, rb
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

void	rotate_both(t_stack **a, t_stack **b) // rr
{
	rotate(a);
	rotate(b);
}
