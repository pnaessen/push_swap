/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:34:32 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/10 12:12:54 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_push_a_to_b(t_stack **a, t_stack **b, int *cmp_index)
{
	(*cmp_index)++;
	push_to(a, b);
	write(1, "pb\n", 3);
}

void	handle_push_kr(t_stack **a, t_stack **b, int *cmp_index)
{
	handle_push_a_to_b(a, b, cmp_index);
	if ((*a) && (*a)->index >= *cmp_index)
	{
		rotate_both(a, b);
		write(1, "rr\n", 3);
	}
	else
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
}

void	process_push_kr(t_stack **a, t_stack **b, float chunk)
{
	int	cmp_index;

	cmp_index = 0;
	while (*a)
	{
		if ((*a)->index <= cmp_index)
			handle_push_a_to_b(a, b, &cmp_index);
		else if ((*a) && (*a)->index < (cmp_index + chunk))
			handle_push_kr(a, b, &cmp_index);
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
	}
}

void	parkinson_algo(t_stack **a, t_stack **b)
{
	int	max;
	int	pos;

	while (*b)
	{
		max = max_nbr(*b);
		pos = get_position(*b, max);
		while ((*b)->data != max)
			the_greatest_rot_ever_that_human_can_imagine(b, pos);
		push_to(b, a);
		write(1, "pa\n", 3);
	}
}

void	the_greatest_rot_ever_that_human_can_imagine(t_stack **b,
		int pos)
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
