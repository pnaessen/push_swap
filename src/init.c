/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:12:39 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/27 00:27:20 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *joined_args;
    char **split_args_result;
    int count;
    t_stack *stack_a = NULL;

    joined_args = strjoin(argc, argv);
    if (!joined_args)
        return (1);
    split_args_result = split_args(joined_args, &count);
    free(joined_args);
    if (!split_args_result)
        return (1);
    if (process_args(split_args_result, count, &stack_a) != 0)
    {
        free_split_args(split_args_result, count);
        return (1);
    }
    free_split_args(split_args_result, count);
    print_stack(stack_a);
    free_stack(&stack_a);
    return (0);
}

int process_args(char **split_args, int count, t_stack **stack)
{
    int value;
    int i;

    i = 0;
    while (i < count)
    {
        value = ft_atoi(split_args[i]);
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

int is_duplicate(t_stack *head, int value)
{
    while (head)
    {
        if (head->data == value)
            return (1);
        head = head->next;
    }
    return (0);
}

void free_split_args(char **split_args, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        free(split_args[i]);
        i++;
    }
    free(split_args);
}
