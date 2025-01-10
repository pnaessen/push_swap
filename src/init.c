/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:12:39 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/10 10:35:23 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	choice_algo(&stack_a, &stack_b, count);
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
		value = ft_atol(split_args[i], stack, split_args, count);
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

void	choice_algo(t_stack **a, t_stack **b, int size)
{
	if (is_sorted(*a))
		return ;
	if (size == 3)
		sort_three(a);
	else if (size <= 12)
		insertion_sort(a, b);
	else if (size <= 100)
		the_greatest_korean_sort_made_by_pierrick(a, b);
	else if (size <= 300)
		radix_sort(a, b, size);
	else
		the_greatest_korean_sort_made_by_pierrick(a, b);
}
