/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:08 by pn                #+#    #+#             */
/*   Updated: 2024/12/31 17:27:55 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **a, t_stack **b, int size) // trie par bytes
{
	int max_num;
	int max_bits;
	int i;
	int count;

	max_num = max_nbr(*a);
	max_bits = 0;
	i = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		count = size;
		while (count > 0)
		{
			if ((((*a)->data >> i) & 1) == 1)
			{
				rotate(a);
				write(1, "ra\n", 3);
			}
			else
			{
				push_to(a, b);
				write(1, "pb\n", 3);
			}
			count--;
		}
		while (*b)
		{
			push_to(b, a);
			write(1, "pa\n", 3);
		}
		i++;
	}
}

void	push_chunk_to_b(t_stack **a, t_stack **b, int min_val, int max_val,
		int *count)
{
	while (*count > 0 && *a)
	{
		if ((*a)->data >= min_val && (*a)->data < max_val)
		{
			push_to(a, b);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		(*count)--;
	}
}

void	chunk_sort(t_stack **a, t_stack **b, int size)
{
	int	chunk_size;
	int	min_stack;
	int	max_stack;
	int	min_val;
	int	max_val;
	int	i;
	int	count;

	min_stack = min_nbr(*a);
	max_stack = max_nbr(*a);
	chunk_size = (max_stack - min_stack) / 5 + 1;
	i = 0;
	while (i < 5)
	{
		min_val = min_stack + i * chunk_size;
		max_val = min_stack + (i + 1) * chunk_size;
		count = size;
		push_chunk_to_b(a, b, min_val, max_val, &count);
		i++;
	}
	move_all_b_to_a(a, b);
}

void	bubble_sort(t_stack **a, int size)
{
	int	swapped;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if ((*a)->data > (*a)->next->data)
			{
				swap(*a);
				swapped = 1;
			}
			rotate(a);
			write(1, "ra\n", 3);
			j++;
		}
		while (j-- > 0)
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}
		if (!swapped)
			break ;
		i++;
	}
}
