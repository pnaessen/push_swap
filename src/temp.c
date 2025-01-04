/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:10:03 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/04 14:21:37 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mechanical_turk_sort(t_stack **a, t_stack **b, int size)
{
	int	chunk_size;
	int	max;
	int	min_val;
	int	max_val;

	chunk_size = size / 10;
	while (*a)
	{
		min_val = min_nbr(*a);
		max_val = min_val + chunk_size;
		while (elem_in_chunk(a, min_val, max_val))
		{
			if ((*a)->data >= min_val && (*a)->data <= max_val)
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
	}
	while (*b)
	{
		max = max_nbr(*b);
		move_max_to_top(b, max);
		push_to(b, a);
		 write(1, "pa\n", 3);
	}
}

void	move_max_to_top(t_stack **b, int max)
{
	int	position;
	int	size;

	position = get_position(*b, max);
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

int	elem_in_chunk(t_stack **a, int min_val, int max_val)
{
	t_stack	*tmp;
	int		count;

	tmp = *a;
	count = 0;
	while (tmp)
	{
		if (tmp->data >= min_val && tmp->data < max_val)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
