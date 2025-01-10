/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:08:36 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/10 08:51:28 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	int				index;
	struct s_stack	*prev;

}					t_stack;

typedef struct s_chunk
{
	int				min;
	int				max;
	int				pushed;
}					t_chunk;

///////tools.c////
void				swap(t_stack *stack);
void				swap_both(t_stack *a, t_stack *b);
void				push_to(t_stack **src, t_stack **dest);
void				rotate(t_stack **stack);
void				rotate_both(t_stack **a, t_stack **b);

///////tools2.c////
int					is_valid_number(const char *str);
void				reverse_rotate(t_stack **stack);
void				reverse_rotate_both(t_stack **a, t_stack **b);
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
int					ft_atol(char *str, t_stack **stack, char **split_args,
						int count);
int					calculate_length(int argc, char **argv);
const char			*skip_whitespace(const char *str);
void				*free_all(char **res, int count);

//////////algo.c//////////
void				radix_sort(t_stack **a, t_stack **b, int size);
void				insertion_sort(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
void				the_greatest_korean_sort_made_by_pierrick(t_stack **a,
						t_stack **b);

//////////algo_tools.c//////////
int					max_nbr(t_stack *head);
int					min_nbr(t_stack *head);
void				smallest_to_top(t_stack **a, int size);
void				push_all_back(t_stack **b, t_stack **a);
void				handle_three(t_stack **a, int first, int second, int third);

//////////init.c//////////
int					process_args(char **split_args, int count, t_stack **stack);
void				choice_algo(t_stack **a, t_stack **b, int size);

/////////utils.c////////
void				process_radix_bit(t_stack **a, t_stack **b, int size,
						int bit);
void				index_stack(t_stack **stack);
int					is_duplicate(t_stack *head, int value);
void				print_stack(t_stack *stack);

///////the_one.c/////
void				process_push_kr(t_stack **a, t_stack **b, float chunk);
void				the_greatest_rotation_ever_that_human_brain_can_imagine(t_stack **b,
						int pos);
void				parkinson_algo(t_stack **a, t_stack **b);
void				handle_push_kr(t_stack **a, t_stack **b, int *cmp_index);
void				handle_push_a_to_b(t_stack **a, t_stack **b,
						int *cmp_index);

//////////checker_init.c/////////////
int					ft_strcmp(const char *s1, const char *s2);
int					check_instruction(t_stack **a, t_stack **b, char *line);

#endif