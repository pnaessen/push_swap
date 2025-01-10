/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:49:40 by pn                #+#    #+#             */
/*   Updated: 2025/01/10 08:51:35 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(char *str, t_stack **stack, char **split_args, int count)
{
	int			i;
	int			sign;
	long int	nb;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i++] <= '9')
		nb = nb * 10 + (str[i - 1] - '0');
	if (nb * sign > INT_MAX || nb * sign < INT_MIN)
	{
		write(1, "Error\n", 6);
		free_split_args(split_args, count);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	return ((int)(nb * sign));
}

int	calculate_length(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len + argc - 2);
}

const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

void	*free_all(char **res, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}
