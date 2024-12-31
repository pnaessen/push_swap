/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:10:42 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/31 14:48:43 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack) // sa, sb
{
	int temp;

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
	t_stack *temp;

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
	t_stack *temp;
	t_stack *current;

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

void	reverse_rotate(t_stack **stack) // rra, rrb
{
	t_stack *prev;
	t_stack *current;

	if (*stack && (*stack)->next)
	{
		prev = NULL;
		current = *stack;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		current->next = *stack;
		*stack = current;
	}
}

void	reverse_rotate_both(t_stack **a, t_stack **b) // rrr
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	print_stack(t_stack *stack) // debug
{
	while (stack)
	{
		printf("%d\n", stack->data);
		stack = stack->next;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
