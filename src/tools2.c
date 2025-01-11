/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:14:52 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/11 17:10:13 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	if (*stack && (*stack)->next != *stack)
		*stack = (*stack)->prev;
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
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

t_stack	*pop_from(t_stack **src)
{
	t_stack	*temp;

	temp = NULL;
	if (*src)
	{
		temp = *src;
		if ((*src)->next == *src)
			*src = NULL;
		else
		{
			*src = (*src)->next;
			(*src)->prev = temp->prev;
			temp->prev->next = *src;
		}
	}
	return (temp);
}

void	add_to(t_stack **dest, t_stack *temp)
{
	if (temp)
	{
		if (*dest)
		{
			temp->next = *dest;
			temp->prev = (*dest)->prev;
			(*dest)->prev->next = temp;
			(*dest)->prev = temp;
		}
		else
		{
			temp->next = temp;
			temp->prev = temp;
		}
		*dest = temp;
	}
}
