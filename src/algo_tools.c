/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:25:44 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/31 17:27:53 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_max_to_top(t_stack **stack, int max)
{
	while ((*stack)->data != max)
	{
		rotate(stack);
		write(1, "rb\n", 3);
	}
}

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

void	move_all_b_to_a(t_stack **a, t_stack **b)
{
	int	max;

	while (*b)
	{
		max = max_nbr(*b);
		move_max_to_top(b, max);
		if (*b)
		{
			push_to(b, a);
			write(1, "pa\n", 3);
		}
	}
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
