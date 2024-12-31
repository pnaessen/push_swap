/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:12:39 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/31 17:27:11 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*joined_args;
	char	**split_args_result;
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	joined_args = strjoin(argc, argv);
	if (!joined_args)
		return (1);
	split_args_result = split_args(joined_args, &count);
	free(joined_args);
	if (!split_args_result)
		return (1);
	if (process_args(split_args_result, count, &stack_a) != 0)
		return (free_split_args(split_args_result, count), 1);
	free_split_args(split_args_result, count);
	//choice_algo(&stack_a, &stack_b, count);
	//print_stack(stack_a);
	radix_sort(&stack_a, &stack_b, count);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int	process_args(char **split_args, int count, t_stack **stack)
{
	int	value;
	int	i;

	i = 0;
	while (i < count)
	{
		value = ft_atoi(split_args[i], stack, split_args, count);
		if (is_duplicate(*stack, value))
		{
			write(1, "Error\n", 6);
			free_stack(stack);
			*stack = NULL;
			return (1);
		}
		add_back(stack, value);
		i++;
	}
	return (0);
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

void	choice_algo(t_stack **a, t_stack **b, int size)
{
	if (size <= 10)
		bubble_sort(a, size);
	else if (size <= 100)
		chunk_sort(a, b, size);
	else
		radix_sort(a, b, size);
}
