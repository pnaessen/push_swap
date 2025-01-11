/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:10:42 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/11 17:10:26 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a)
{
	int	temp_data;
	int	temp_index;

	if (a && a->next)
	{
		temp_data = a->data;
		a->data = a->next->data;
		a->next->data = temp_data;
		temp_index = a->index;
		a->index = a->next->index;
		a->next->index = temp_index;
	}
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	push_to(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	temp = pop_from(src);
	add_to(dest, temp);
}

void	rotate(t_stack **stack)
{
	if (*stack && (*stack)->next != *stack)
		*stack = (*stack)->next;
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
