/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:27:30 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/04 09:27:38 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_radix_bit(t_stack **a, t_stack **b, int size, int bit)
{
	int count;

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
