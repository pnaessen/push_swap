/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:10:03 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/03 12:16:09 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mechanical_turk_sort(t_stack **a, t_stack **b, int size)
{
	int	num_chunks;
	int	chunk_size;
	int	i;
	int	max;

	num_chunks = size / 40 + 5;
	chunk_size = size / num_chunks;
	int min_val, max_val;
	i = 0;
	while (i < num_chunks)
	{
		min_val = get_min_value(*a) + i * chunk_size;
		max_val = get_min_value(*a) + (i + 1) * chunk_size;
		while (has_elements_in_range(*a, min_val, max_val))
		{
			if ((*a)->data >= min_val && (*a)->data < max_val)
			{
				push_to(a, b);
				write(1, "pb\n", 3);
				if ((*b)->data < (min_val + max_val) / 2)
				{
					rotate(b);
					write(1, "rb\n", 3);
				}
			}
			else
			{
				write(1, "ra\n", 3);
				rotate(a);
			}
		}
		i++;
	}
	while (has_elements_in_range(*a, min_val, max_val))
	{
		write(1, "ra\n", 3);
		rotate(a);
	}
	if (*a && !is_sorted(*a))
	{
		last_sort(a);
	}
	while (*b)
	{
		max = get_max_value(*b);
		move_max_to_top(b, max);
		push_to(b, a);
		write(1, "pa\n", 3);
	}
}

void	last_sort(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	if (!a || !*a)
		return ;
	current = *a;
	while (current && current->next)
	{
		if (current->data > current->next->data)
		{
			next = current->next;
			current->next = next->next;
			next->next = current;
			*a = next;
			current = *a;
		}
		else
		{
			current = current->next;
		}
	}
}

int	has_elements_in_range(t_stack *stack, int min_val, int max_val)
{
	while (stack)
	{
		if (stack->data >= min_val && stack->data < max_val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	move_max_to_top(t_stack **b, int max)
{
	int	position;
	int	size;

	position = get_pos(*b, max);
	size = stack_size(*b);
	if (position <= size / 2)
	{
		while ((*b)->data != max)
		{
			rotate(b);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		while ((*b)->data != max)
		{
			reverse_rotate(b);
			write(1, "rrb\n", 4);
		}
	}
}

int	get_min_value(t_stack *stack)
{
	int	min;

	min = stack->data;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	get_max_value(t_stack *stack)
{
	int	max;

	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	get_pos(t_stack *stack, int value)
{
	int position = 0;
	while (stack)
	{
		if (stack->data == value)
			break ;
		stack = stack->next;
		position++;
	}
	return (position);
}