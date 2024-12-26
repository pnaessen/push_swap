/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:08:36 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/27 00:25:29 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
	int data;
	struct s_stack *next;
} t_stack;

///////tools.c////
void free_stack(t_stack **stack);
void swap(t_stack *stack);							// sa, sb
void swap_both(t_stack *a, t_stack *b);				// ss
void push_to(t_stack **src, t_stack **dest);		// pa, pb
void rotate(t_stack **stack);						// ra, rb
void rotate_both(t_stack **a, t_stack **b);			// rr
void reverse_rotate(t_stack **stack);				// rra, rrb
void reverse_rotate_both(t_stack **a, t_stack **b); // rrr
void print_stack(t_stack *stack);

///////list.c////
t_stack *new_node(int value);
void add_back(t_stack **head, int value);

///////pars.c////
char *strjoin(int argc, char **argv);
const char *skip_word(const char *str);
int count_words(const char *str);
char *allocate_word(const char *start, const char *end);
char **split_args(const char *str, int *count);
int is_valid_number(const char *str); // a deplace

///////tools_pars.c////
int ft_atoi(char *str);
char *ft_strlcpy(char *dst, const char *src, size_t size);
int calculate_length(int argc, char **argv);
const char *skip_whitespace(const char *str);
void *free_all(char **res, int count);

int process_args(char **split_args, int count, t_stack **stack);
int is_duplicate(t_stack *head, int value);
void free_split_args(char **split_args, int count);

#endif