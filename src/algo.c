/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:08 by pn                #+#    #+#             */
/*   Updated: 2024/12/28 00:47:23 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix_sort(t_stack **a, t_stack **b, int size) // trie par bytes
{
    int max_num;
    int max_bits;
    int i;
    int count;

    max_num = max_nbr(*a);
    max_bits = 0;
    i = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;
    while (i < max_bits)
    {
        count = size;
        while (count > 0)
        {
            if ((((*a)->data >> i) & 1) == 1)
                rotate(a);
            else
                push_to(a, b);
            count--;
        }
        while (*b)
            push_to(b, a);
        i++;
    }
}

int min_nbr(t_stack *head)
{
    int min;

    min = head->data;
    while (head)
    {
        if (head->data < min)
            min = head->data;
        head = head->next;
    }
    return (min);
}
void push_chunk_to_b(t_stack **a, t_stack **b, int min_val, int max_val, int *count)
{
    while (*count > 0 && *a)
    {
        if ((*a)->data >= min_val && (*a)->data < max_val)
            push_to(a, b);
        else
            rotate(a);
        (*count)--;
    }
}
void move_all_b_to_a(t_stack **a, t_stack **b)
{
    while (*b)
    {
        int max = max_nbr(*b);
        move_max_to_top(b, max);
        if (*b)
            push_to(b, a);
    }
}
void chunk_sort(t_stack **a, t_stack **b, int size)
{
    int chunk_size;
    int min_stack;
    int max_stack;
    int min_val;
    int max_val;
    int i;

    min_stack = min_nbr(*a);
    max_stack = max_nbr(*a);
    chunk_size = (max_stack - min_stack) / 5 + 1;
    i = 0;
    while (i < 5)
    {
        min_val = min_stack + i * chunk_size;
        max_val = min_stack + (i + 1) * chunk_size;
        int count = size;
        push_chunk_to_b(a, b, min_val, max_val, &count);
        i++;
    }
    move_all_b_to_a(a, b);
}

void move_max_to_top(t_stack **stack, int max)
{
    while ((*stack)->data != max)
        rotate(stack);
}
