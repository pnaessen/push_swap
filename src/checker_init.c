/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:30:02 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/10 09:15:47 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		value;
	int		i;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			free_stack(&stack_a);
			exit(EXIT_FAILURE);
		}
		value = ft_atoi(argv[i]);
		i++;
		add_back(&stack_a, value);
	}
	if (is_sorted(stack_a) && stack_b == NULL)
	{
		write(1, "OK\n", 3);
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!check_instruction(&stack_a, &stack_b, line))
		{
			write(2, "Error\n", 6);
			free(line);
			free_stack(&stack_a);
			free_stack(&stack_b);
			return (1);
		}
		//print_stack(stack_a);
		if (is_sorted(stack_a) && stack_b == NULL)
		{
			write(1, "OK\n", 3);
			free(line);
			free_stack(&stack_a);
			free_stack(&stack_b);
			return (0);
		}
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (t1[i] != '\n')
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		if (t1[i + 1] == '\n' && t2[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}
