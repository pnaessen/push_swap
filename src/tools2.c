/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:14:52 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/09 11:21:07 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9') && *str != ' ' && *str != '-')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		str++;
	}
	return (1);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;

	if (*stack && (*stack)->next)
	{
		prev = NULL;
		current = *stack;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		current->next = *stack;
		*stack = current;
	}
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || stack == NULL)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	free_split_args(char **split_args, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}
