/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:25:44 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/11 16:56:30 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_nbr(t_stack *head)
{
	t_stack	*temp;
	int		min;

	if (!head)
		return (0);
	temp = head;
	min = temp->data;
	while (1)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
		if (temp == head)
			break ;
	}
	return (min);
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

void	push_all_back(t_stack **b, t_stack **a)
{
	while (*b)
	{
		push_to(b, a);
		write(1, "pa\n", 3);
	}
}

int	get_position(t_stack *stack, int value)
{
	int		position;
	t_stack	*start;

	if (!stack)
		return (-1);
	position = 0;
	start = stack;
	while (1)
	{
		if (stack->data == value)
			return (position);
		stack = stack->next;
		position++;
		if (stack == start)
			break ;
	}
	return (-1);
}
