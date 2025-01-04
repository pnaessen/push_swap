/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:25:44 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/04 09:22:13 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_nbr(t_stack *head)
{
	int	min;

	min = head->data;
	while (head)
	{
		if (head->data < min)
			min = head->data;
		head = head->next;
	}
	return (min);
}

int	max_nbr(t_stack *head)
{
	int	max;

	if (!head)
		return (-1);
	max = head->data;
	while (head)
	{
		if (head->data > max)
			max = head->data;
		head = head->next;
	}
	return (max);
}

void	smallest_to_top(t_stack **a, int size)
{
	int	min;
	int	position;
	int	mid;

	min = min_nbr(*a);
	position = get_position(*a, min);
	mid = size / 2;
	if (position == 0)
		return ;
	while ((*a)->data != min)
	{
		if (position <= mid)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		else
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}
	}
}

void	push_all_back(t_stack **b, t_stack **a)
{
	while (*b)
	{
		push_to(b, a);
		write(1, "pa\n", 3);
	}
}

void	handle_three(t_stack **a, int first, int second, int third)
{
	if (first > second && second > third)
	{
		swap(*a);
		write(1, "sa\n", 3);
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	else if (first < second && second > third && first < third)
	{
		swap(*a);
		write(1, "sa\n", 3);
		rotate(a);
		write(1, "ra\n", 3);
	}
}
