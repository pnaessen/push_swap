/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:30:02 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/10 12:21:59 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	pars_check_and_create(&stack_a, &stack_b, argc, argv);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		instruction_and_update(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (!is_sorted(stack_a) || stack_b != NULL)
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int	check_instruction(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(*a);
	else if (ft_strcmp(line, "sb") == 0)
		swap(*b);
	else if (ft_strcmp(line, "ss") == 0)
		swap_both(*a, *b);
	else if (ft_strcmp(line, "pa") == 0)
		push_to(b, a);
	else if (ft_strcmp(line, "pb") == 0)
		push_to(a, b);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_both(a, b);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(line, "rrr") == 0)
		reverse_rotate_both(a, b);
	else
		return (0);
	return (1);
}

int	is_argv_valid(const char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9') && *str != ' ' && *str != '-')
			return (0);
		str++;
	}
	return (1);
}
