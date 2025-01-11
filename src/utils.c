/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:27:30 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/11 16:56:16 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *stack, int value)
{
	t_stack	*start;

	if (!stack)
		return (0);
	start = stack;
	while (1)
	{
		if (stack->data == value)
			return (1);
		stack = stack->next;
		if (stack == start)
			break ;
	}
	return (0);
}

int	find_max_index(t_stack *stack)
{
	int		i;
	int		len;
	t_stack	*head;
	int		max;

	if (!stack)
		return (1);
	head = stack;
	len = stack_size(stack);
	i = -1;
	max = 0;
	while (++i < len)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	stack = head;
	return (max);
}

void	init_index(t_stack **stack)
{
	const int	len = stack_size(*stack);
	int			i;
	t_stack		*head;

	i = -1;
	head = *stack;
	while (++i < len)
	{
		get_index(*stack);
		*stack = (*stack)->next;
	}
	*stack = head;
}

void	get_index(t_stack *stack)
{
	int				i;
	int				len;
	t_stack			*head;
	unsigned int	index;

	len = stack_size(stack);
	i = -1;
	index = 0;
	head = stack;
	while (++i < len)
	{
		if (head->data > stack->data)
			index++;
		stack = stack->next;
	}
	stack->index = index;
	stack = head;
}
