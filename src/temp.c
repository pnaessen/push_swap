/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:10:03 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/08 09:50:44 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk_to_b(t_stack **a, t_stack **b, int min_val, int max_val,
		int median)
{
	while (elem_in_chunk(a, min_val, max_val))
	{
		if ((*a)->data >= min_val && (*a)->data < max_val)
		{
			push_to(a, b);
			write(1, "pb\n", 3);
			if ((*b)->data < median && (*b)->next)
			{
				rotate(b);
				write(1, "rb\n", 3);
			}
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
	}
}

void	execute_rotation(t_stack **b, int pos)
{
	int	size;

	size = stack_size(*b);
	if (pos <= size / 2)
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

void	push_back_sorted(t_stack **b, t_stack **a)
{
	int	max;
	int	pos;

	while (*b)
	{
		max = max_nbr(*b);
		pos = get_position(*b, max);
		while ((*b)->data != max)
			execute_rotation(b, pos);
		push_to(b, a);
		write(1, "pa\n", 3);
	}
}

int	elem_in_chunk(t_stack **a, int min_val, int max_val)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->data >= min_val && tmp->data < max_val)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	find_closest_in_chunk(t_stack *a, int min_val, int max_val)
{
	t_stack	*tmp;
	int		pos;

	tmp = a;
	pos = 0;
	while (tmp)
	{
		if (tmp->data >= min_val && tmp->data < max_val)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (0);
}
