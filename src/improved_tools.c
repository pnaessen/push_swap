/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:45:58 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/03 10:57:58 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_push(t_stack **a, t_stack **b, int min, int max, int pushed)
{
	int	closest;

	if ((*a)->index >= min && (*a)->index < max)
	{
		push_to(a, b);
		write(1, "pb\n", 3);
		return (pushed + 1);
	}
	closest = find_closest_in_range(a, min, max);
	if (closest <= stack_size(*a) / 2)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	return (pushed);
}

void	push_back_to_a(t_stack **a, t_stack **b, int size)
{
	int	target;
	int	pos;

	while (*b)
	{
		target = size - 1;
		pos = find_position(*b, target);
		if (pos == 0)
		{
			push_to(b, a);
			write(1, "pa\n", 3);
			size--;
		}
		else if (pos <= stack_size(*b) / 2)
		{
			rotate(b);
			write(1, "rb\n", 3);
		}
		else
		{
			reverse_rotate(b);
			write(1, "rrb\n", 4);
		}
	}
}

int	find_closest_in_range(t_stack **a, int min, int max)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index >= min && tmp->index < max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	find_position(t_stack *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack && stack->index != target)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	index_stack(t_stack **stack)
// compare pour combien d'élém sont plus petits que l'élém actuel
{
	t_stack *current;
	t_stack *compare;
	int index;

	current = *stack;
	while (current)
	{
		index = 0;
		compare = *stack;
		while (compare)
		{
			if (compare->data < current->data)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}