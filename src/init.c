/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:12:39 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/20 16:53:43 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*datas;
	t_stack	*stack = NULL;

	//(void)argv;
	//(void)argc;
	if (argc < 2)
		return (0);
	datas = get_datas(argc, argv);
	if (!datas)
		return (0);
	free(datas);
	if (!stack)
		return (0);
	free_stack(&stack);
	return (0);
}
