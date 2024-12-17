/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:10:42 by aviscogl          #+#    #+#             */
/*   Updated: 2024/12/17 22:10:42 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack)
{
    if (stack && stack->next)
    {
        int temp = stack->value;
        stack->value = stack->next->value;
        stack->next->value = temp;
    }
}

void swap_both(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
}

void push_to(t_stack **src, t_stack **dest)
{
    if (*src)
    {
        t_stack *temp = *src;
        *src = (*src)->next;
        temp->next = *dest;
        *dest = temp;
    }
}

void rotate(t_stack **stack)
{
    if (*stack && (*stack)->next)
    {
        t_stack *temp = *stack;
        *stack = (*stack)->next;
        temp->next = NULL;

        t_stack *current = *stack;
        while (current->next)
            current = current->next;
        current->next = temp;
    }
}

void rotate_both(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
}

void reverse_rotate(t_stack **stack)
{
    if (*stack && (*stack)->next)
    {
        t_stack *prev = NULL;
        t_stack *current = *stack;
        while (current->next)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        current->next = *stack;
        *stack = current;
    }
}

void reverse_rotate_both(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}

t_stack *stack_init(int *values, int size)
{
    t_stack *stack = NULL;
    int i = size - 1;
    while (i >= 0)
    {
        push(&stack, values[i]);
        i--;
    }
    return stack;
}

void push(t_stack **stack, int value)
{
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}


void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}

void free_stack(t_stack **stack)
{
    while (*stack)
    {
        t_stack *temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}
