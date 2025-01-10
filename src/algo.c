/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:08 by pn                #+#    #+#             */
/*   Updated: 2025/01/10 08:39:12 by pnaessen         ###   ########lyon.fr   */
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

void	the_greatest_korean_sort_made_by_pierrick(t_stack **a, t_stack **b)
{
	const size_t	size = stack_size(*a);
	float			chunk;

	index_stack(a);
	if (size <= 100)
		chunk = (0.000008 * (size * size)) + (0.03 * size) + 11;
	else
		chunk = (0.000008 * (size * size)) + (0.03 * size) + 18;
	process_push_kr(a, b, chunk);
	parkinson_algo(a, b);
}
