/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:34:32 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/08 12:48:51 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_greatest_korean_sort_made_by_PIERRICK(t_stack **a, t_stack **b)
{
	const size_t	size = stack_size(*a);
	float			chunk;

	index_stack(a);
	if (size <= 100)
		chunk = (0.000008 * (size * size)) + (0.03 * size) + 11;
	else
		chunk = (0.000008 * (size * size)) + (0.03 * size) + 18;
	process_push_kr(a, b, chunk);
	// sort_three(a);
	parkinson_algo(a, b);
}
void	process_push_kr(t_stack **a, t_stack **b, float chunk)
{
	size_t	size;
	int		cmp_index;

	size = stack_size(*a);
	cmp_index = 0;
	while (*a) // ou size > 3
	{
		if ((*a)->index <= cmp_index)
		{
			size--;
			cmp_index++;
			push_to(a, b);
			write(1, "pb\n", 3);
		}
		else if ((*a) && (*a)->index < (cmp_index + chunk)) // 03 21 54 77 70
		{
			size--;
			cmp_index++;
			push_to(a, b);
			write(1, "pb\n", 3);
			if ((*a)->index >= cmp_index)
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
			the_greatest_rotation_ever_that_human_brain_can_imagine(b, pos);
		push_to(b, a);
		write(1, "pa\n", 3);
	}
}

void	the_greatest_rotation_ever_that_human_brain_can_imagine(t_stack **b,
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
