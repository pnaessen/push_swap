/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:08:36 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/04 12:52:46 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	int				index;
}					t_stack;

///////tools.c////
void	swap(t_stack *stack);                   // sa, sb
void	swap_both(t_stack *a, t_stack *b);      // ss
void	push_to(t_stack **src, t_stack **dest); // pa, pb
void	rotate(t_stack **stack);                // ra, rb
void	rotate_both(t_stack **a, t_stack **b);  // rr

///////tools2.c////
int					is_valid_number(const char *str);
void	reverse_rotate(t_stack **stack);               // rra, rrb
void	reverse_rotate_both(t_stack **a, t_stack **b); // rrr
void				free_stack(t_stack **stack);
void				free_split_args(char **split_args, int count);

///////list.c////
t_stack				*new_node(int value);
void				add_back(t_stack **head, int value);
int					is_sorted(t_stack *stack);
int					stack_size(t_stack *stack);
int					get_position(t_stack *stack, int value);

///////pars.c////
int					count_words(const char *str);
const char			*skip_word(const char *str);
char				*strjoin(int argc, char **argv);
char				*allocate_word(const char *start, const char *end);
char				**split_args(const char *str, int *count);

///////tools_pars.c////
int					ft_atoi(char *str, t_stack **stack, char **split_args,
						int count);
char				*ft_strlcpy(char *dst, const char *src, size_t size);
int					calculate_length(int argc, char **argv);
const char			*skip_whitespace(const char *str);
void				*free_all(char **res, int count);

//////////algo.c//////////
void				radix_sort(t_stack **a, t_stack **b, int size);
void				insertion_sort(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
void				improved_sort(t_stack **a, t_stack **b, int size);

//////////algo_tools.c//////////
int					max_nbr(t_stack *head);
int					min_nbr(t_stack *head);
void				smallest_to_top(t_stack **a, int size);
void				push_all_back(t_stack **b, t_stack **a);
void				handle_three(t_stack **a, int first, int second, int third);

//////////init.c//////////
int					process_args(char **split_args, int count, t_stack **stack);
int					is_duplicate(t_stack *head, int value);
void				choice_algo(t_stack **a, t_stack **b, int size);

/////////improved_tools.c////////
int					find_closest(t_stack **a, int min, int max);
void				push_back_to_a(t_stack **a, t_stack **b, int size);
int					find_position(t_stack *stack, int value);
void				index_stack(t_stack **stack);
int					process_push(t_stack **a, t_stack **b, int min, int max,
						int pushed);

/////////utils.c////////
void				process_radix_bit(t_stack **a, t_stack **b, int size,
						int bit);

void				move_max_to_top(t_stack **b, int max);
void				mechanical_turk_sort(t_stack **a, t_stack **b, int size);
int					elem_in_chunk(t_stack **a, int min_val, int max_val);


#endif