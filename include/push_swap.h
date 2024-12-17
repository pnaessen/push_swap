/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:08:36 by aviscogl          #+#    #+#             */
/*   Updated: 2024/12/17 22:08:36 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

t_stack *stack_init(int *values, int size);
void push(t_stack **stack, int value);
void print_stack(t_stack *stack);
void free_stack(t_stack **stack);

void swap(t_stack *stack);        // sa, sb
void swap_both(t_stack *a, t_stack *b); // ss
void push_to(t_stack **src, t_stack **dest); // pa, pb
void rotate(t_stack **stack);     // ra, rb
void rotate_both(t_stack **a, t_stack **b);  // rr
void reverse_rotate(t_stack **stack); // rra, rrb
void reverse_rotate_both(t_stack **a, t_stack **b); // rrr

#endif