/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:08 by pn                #+#    #+#             */
/*   Updated: 2025/01/07 14:10:54 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	max_num;
	int	max_bits;
	int	bit;

	max_num = max_nbr(*a);
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		process_radix_bit(a, b, size, bit);
		push_all_back(b, a);
		bit++;
		if (is_sorted(*a))
			return ;
	}
}

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
	sort_three(a);
	push_all_back(b, a);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*a))
		return ;
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

void	improved_sort(t_stack **a, t_stack **b, int size)
{
	int		chunk_size;
	t_chunk	chunk;

	chunk_size = size / 5;
	chunk.min = 0;
	chunk.max = chunk_size;
	chunk.pushed = 0;
	index_stack(a);
	while (*a)
	{
		chunk.pushed = process_push(a, b, chunk.min, chunk.max, chunk.pushed);
		if (chunk.pushed == chunk.max - chunk.min || stack_size(*a) == 0)
		{
			chunk.min = chunk.max;
			chunk.max += chunk_size;
			if (chunk.max > size)
				chunk.max = size;
			chunk.pushed = 0;
		}
	}
	push_back_to_a(a, b, size);
}
void	not_mechanical_turk_sort(t_stack **a, t_stack **b, int size)
{
	int chunk_size;
	int min_val;
	int max_val;
	int median;

	chunk_size = size / 11;
	if (size <= 100)
		chunk_size = size / 5;
	while (*a)
	{
		min_val = min_nbr(*a);
		max_val = min_val + chunk_size;
		median = (min_val + max_val) / 2;
		push_chunk_to_b(a, b, min_val, max_val, median);
	}
	push_back_sorted(b, a);
}