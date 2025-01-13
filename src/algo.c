/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:08 by pn                #+#    #+#             */
/*   Updated: 2025/01/13 08:54:45 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->data > (*a)->next->data)
		{
			swap(*a);
			write(1, "sa\n", 3);
		}
	}
	while (size > 3)
	{
		if (is_sorted(*a) && !(*b))
			return ;
		smallest_to_top(a, size);
		push_to(a, b);
		write(1, "pb\n", 3);
		size--;
	}
	if (size == 3)
		sort_three(a);
	push_all_back(b, a);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (first > second && second < third && first < third)
	{
		swap(*a);
		write(1, "sa\n", 3);
	}
	else if (first > second && second < third && first > third)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (first < second && second > third && first > third)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	else
		handle_three(a, first, second, third);
}

void	the_greatest_korean_sort(t_stack **a, t_stack **b)
{
	const size_t	size = stack_size(*a);
	float			chunk;

	init_index(a);
	if (size <= 100)
		chunk = (QUADRATIQUE * (size * size)) + (0.03 * size) + CHUNK_LARGE;
	else
		chunk = (QUADRATIQUE * (size * size)) + (0.03 * size) + CHUNK_LARGE;
	process_push_kr(a, b, chunk);
	sort_three(a);
	parkinson_algo(a, b);
}
