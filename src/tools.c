/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:10:42 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/18 13:32:08 by pnaessen         ###   ########lyon.fr   */
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

t_stack	*stack_init(int *datas, int size)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = size - 1;
	while (i >= 0)
	{
		push(&stack, datas[i]);
		i--;
	}
	return (stack);
}

void	push(t_stack **stack, int data) // pa, pb
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = *stack;
	*stack = new_node;
}

void	print_stack(t_stack *stack)
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
