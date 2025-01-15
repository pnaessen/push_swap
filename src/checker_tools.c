/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:01:20 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/15 13:56:25 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pars_check_and_create(t_stack **a, int argc, char **argv)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		if (!is_argv_valid(argv[i]))
			handle_error(a);
		value = ft_atroi(argv[i], a);
		if (is_duplicate(*a, value))
			handle_error(a);
		i++;
		add_back(a, value);
	}
	return (0);
}

int	instruction_and_update(t_stack **a, t_stack **b, char *line)
{
	if (!check_instruction(a, b, line))
	{
		write(2, "Error\n", 6);
		free(line);
		free_stack(a);
		free_stack(b);
		exit(EXIT_FAILURE);
	}
	if (is_sorted(*a) && *b == NULL)
	{
		write(1, "OK\n", 3);
		free(line);
		free_stack(a);
		free_stack(b);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	handle_error(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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

int	ft_atroi(const char *nptr, t_stack **a)
{
	size_t	i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = nb * 10 + (nptr[i++] - '0');
	nb *= sign;
	if (nb < INT_MIN || nb > INT_MAX)
	{
		free_stack(a);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return ((int)nb);
}
