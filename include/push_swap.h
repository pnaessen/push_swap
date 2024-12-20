/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:08:36 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/20 15:56:38 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void				print_stack(t_stack *stack);
void				free_stack(t_stack **stack);
void	swap(t_stack *stack);                          // sa, sb
void	swap_both(t_stack *a, t_stack *b);             // ss
void	push_to(t_stack **src, t_stack **dest);        // pa, pb
void	rotate(t_stack **stack);                       // ra, rb
void	rotate_both(t_stack **a, t_stack **b);         // rr
void	reverse_rotate(t_stack **stack);               // rra, rrb
void	reverse_rotate_both(t_stack **a, t_stack **b); // rrr
t_stack				*new_node(int value);
void				add_back(t_stack **head, int value);
char				*strjoin(int argc, char **argv);
int					ft_atoi(char *str);
int					*get_datas(int argc, char **argv);

#endif