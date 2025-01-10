/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:27:30 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/10 08:45:53 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_radix_bit(t_stack **a, t_stack **b, int size, int bit)
{
	int	count;

	count = size;
	while (count > 0)
	{
		if ((((*a)->data >> bit) & 1) == 1)
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
}

void	index_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = *stack;
	while (current)
	{
		index = 0;
		compare = *stack;
		while (compare)
		{
			if (compare->data < current->data)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	is_duplicate(t_stack *head, int value)
{
	while (head)
	{
		if (head->data == value)
			return (1);
		head = head->next;
	}
	return (0);
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	printf("Valeurs de la liste : ");
	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
