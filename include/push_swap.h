/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:08:36 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/11 17:05:47 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
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

///////tools.c////
void				swap(t_stack *stack);
void				swap_both(t_stack *a, t_stack *b);
void				push_to(t_stack **src, t_stack **dest);
void				rotate(t_stack **stack);
void				rotate_both(t_stack **a, t_stack **b);

///////tools2.c////
void				reverse_rotate(t_stack **stack);
void				reverse_rotate_both(t_stack **a, t_stack **b);
void				free_split_args(char **split_args, int count);
void				add_to(t_stack **dest, t_stack *temp);
t_stack				*pop_from(t_stack **src);

///////list.c////
t_stack				*new_node(int value);
void				add_back(t_stack **head, int value);
int					is_sorted(t_stack *stack);
int					stack_size(t_stack *stack);
void				free_stack(t_stack **stack);

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
int					is_valid_number(const char *str);

//////////algo.c//////////
void				insertion_sort(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
void				the_greatest_korean_sort_made_by_pierrick(t_stack **a,
						t_stack **b);

//////////algo_tools.c//////////
int					min_nbr(t_stack *head);
void				smallest_to_top(t_stack **a, int size);
void				push_all_back(t_stack **b, t_stack **a);
void				handle_three(t_stack **a, int first, int second, int third);
int					get_position(t_stack *stack, int value);

//////////init.c//////////
int					process_args(char **split_args, int count, t_stack **stack);
void				choice_algo(t_stack **a, t_stack **b, int size);

/////////utils.c////////
int					is_duplicate(t_stack *head, int value);
int					find_max_index(t_stack *stack);
void				get_index(t_stack *stack);
void				init_index(t_stack **stack);

///////kr_tools.c/////
void				handle_push_a_to_b(t_stack **a, t_stack **b, int *cmp_index,
						int *size);
void				handle_push_kr(t_stack **a, t_stack **b, int *cmp_index,
						int *size);
void				process_push_kr(t_stack **a, t_stack **b, float chunk);
void				parkinson_algo(t_stack **a, t_stack **b);
void				push_b_to_a(t_stack **a, t_stack **b, int *max_b);

//////////////kr_utils.c////////////////
int					check_push(t_stack **a, t_stack **b, int max_a, int max_b);
int					the_greatest_rot_ever_that_human_can_imagine(t_stack **b,
						int value);

//////////checker_init.c//////////////////////////
int					check_instruction(t_stack **a, t_stack **b, char *line);
int					is_argv_valid(const char *str);

//////////checker_tools.c//////////////////////////
int					ft_strcmp(const char *s1, const char *s2);
int					instruction_and_update(t_stack **a, t_stack **b,
						char *line);
int					pars_check_and_create(t_stack **a, t_stack **b, int argc,
						char **argv);
void				handle_error(t_stack **a);
int					ft_atroi(const char *nptr, t_stack **a);

#endif