/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:10:03 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/05 14:34:18 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_chunk_to_b(t_stack **a, t_stack **b, int min_val, int max_val, int median)
{
    while (elem_in_chunk(a, min_val, max_val))
    {
        if ((*a)->data >= min_val && (*a)->data < max_val)
        {
            push_to(a, b);
            write(1, "pb\n", 3);
            if ((*b)->data < median && (*b)->next)
            {
                rotate(b);
                write(1, "rb\n", 3);
            }
        }
        else
        {
            if ((*a)->next && (*b) && (*b)->next && (*a)->data < median && (*b)->data < median)
            {
                rotate_both(a, b);
                write(1, "rr\n", 3);
            }
            else
            {
                rotate(a);
                write(1, "ra\n", 3);
            }
        }
    }
}

void execute_rotation(t_stack **a, t_stack **b, int pos, int max)
{
    int size ;

	size = stack_size(*b);
    if (pos <= size / 2)
    {
        if ((*a)->next && (*b)->next && (*a)->data > max && (*b)->data > max)
        {
            rotate_both(a, b);
            write(1, "rr\n", 3);
        }
        else
        {
            rotate(b);
            write(1, "rb\n", 3);
        }
    }
    else
    {
        if ((*a)->next && (*b)->next && (*a)->data > max && (*b)->data > max)
        {
            reverse_rotate_both(a, b);
            write(1, "rrr\n", 4);
        }
        else
        {
            reverse_rotate(b);
            write(1, "rrb\n", 4);
        }
    }
}

void push_back_sorted(t_stack **b, t_stack **a)
{
    int max;
    int pos;

    while (*b)
    {
        max = max_nbr(*b);
        pos = get_position(*b, max);

        while ((*b)->data != max)
            execute_rotation(a, b, pos, max);

        push_to(b, a);
        write(1, "pa\n", 3);
    }
}


void    mechanical_turk_sort(t_stack **a, t_stack **b, int size)
{
    int chunk_size;
    int min_val;
    int max_val;
    int median;

    chunk_size = size / 11;
    if (size <= 100)
        chunk_size = size / 5;
    while (*a)
    {
        min_val = min_nbr(*a);
        max_val = min_val + chunk_size;
        median = (min_val + max_val) / 2;
        push_chunk_to_b(a, b, min_val, max_val, median);
    }
    push_back_sorted(b, a);
}

int elem_in_chunk(t_stack **a, int min_val, int max_val)
{
    t_stack *tmp;

    tmp = *a;
    while (tmp)
    {
        if (tmp->data >= min_val && tmp->data < max_val)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}
