/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:12:39 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/19 17:02:39 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int		*datas;
    t_stack	*stack;

    if (argc < 2)
        return (0);
    datas = get_datas(argc, argv);
    if (!datas)
        return (0);
    stack = stack_init(datas, argc - 1);
    free(datas);
    if (!stack)
        return (0);
    if (is_sorted(stack))
    {
        free_stack(&stack);
        return (0);
    }
    sort_stack(&stack);
    free_stack(&stack);
    return (0);
}
