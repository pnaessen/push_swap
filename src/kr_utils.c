/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kr_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:29:53 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/11 17:01:34 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_push(t_stack **a, t_stack **b, int max_a, int max_b)
{
	if (!*a || !*b)
		return (0);
	if (((*b)->index == max_b || (*a)->prev->index == max_a)
		|| (*b)->index > (*a)->prev->index)
		return (1);
	else
		return (0);
}

int	the_greatest_rot_ever_that_human_can_imagine(t_stack **b, int value)
{
	size_t	i;
	size_t	len;
	t_stack	*head;

	i = 0;
	len = stack_size(*b);
	head = *b;
	while (i < (len / 2))
	{
		if (head->index == value)
		{
			rotate(b);
			write(1, "rb\n", 3);
			return (1);
		}
		head = head->next;
		i++;
	}
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	return (0);
}
