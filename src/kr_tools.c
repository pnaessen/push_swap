/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kr_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:34:32 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/11 16:55:50 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_push_a_to_b(t_stack **a, t_stack **b, int *cmp_index, int *size)
{
	(*cmp_index)++;
	push_to(a, b);
	write(1, "pb\n", 3);
	(*size)--;
}

void	handle_push_kr(t_stack **a, t_stack **b, int *cmp_index, int *size)
{
	handle_push_a_to_b(a, b, cmp_index, size);
	if (*a && (*a)->index >= *cmp_index)
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
	const int	max_index = (find_max_index(*a) - 3);
	int			cmp_index;
	int			size;

	cmp_index = 0;
	size = stack_size(*a);
	while (size > 3)
	{
		if ((*a)->index <= cmp_index && (*a)->index <= max_index)
			handle_push_a_to_b(a, b, &cmp_index, &size);
		else if ((*a)->index < (cmp_index + chunk) && (*a)->index <= max_index)
			handle_push_kr(a, b, &cmp_index, &size);
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
	}
}

void	parkinson_algo(t_stack **a, t_stack **b)
{
	int	max_a;
	int	max_b;

	max_a = find_max_index(*a);
	max_b = find_max_index(*b);
	while (*b || (*a)->prev->index != max_a)
	{
		if ((*a)->prev->index == ((*a)->index - 1))
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}
		else if (check_push(a, b, max_a, max_b))
			push_b_to_a(a, b, &max_b);
		else
			the_greatest_rot_ever_that_human_can_imagine(b, max_b);
	}
}

void	push_b_to_a(t_stack **a, t_stack **b, int *max_b)
{
	push_to(b, a);
	write(1, "pa\n", 3);
	if ((*a)->index != ((*a)->next->index - 1))
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	*max_b = find_max_index(*b);
}
