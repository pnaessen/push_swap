/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:03:51 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/19 17:37:09 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->next = NULL;
	return (new_node);
}
int	atoi(char *str)
{
	int i;
	int sign;
	int nb;

	i = 0;
	nb = 0;
	sign = 1;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
    while(str[i] >= '0' && str[i] <= 9)
    {
        nb = nb * 10 +(str[i] - '0');
        i++;
    }
    return (nb *sign);
}
char *strjoin(int argc, char **argv)
{
    int i;
    int j;
    int k;
    char *str;

    i = 1;
    j = 0;
    k = 0;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
            j++;
        i++;
    }
    str = malloc(sizeof(char) * (j + 1));
    if (!str)
        return (NULL);
    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            str[k] = argv[i][j];
            j++;
            k++;
        }
        i++;
    }
    str[k] = '\0';
    return (str);
}

// int *get_datas(int argc, char **argv)
// {
//     int i;
//     int j;
//     int *datas;
//     char *str;

//     i = 1;
//     j = 0;
//     str = strjoin(argc, argv);
//     if (!str)
//         return (NULL);
//     while (str[j])
//     {
//         if (str[j] == ' ')
//             i++;
//         j++;
//     }
//     datas = malloc(sizeof(int) * i);
//     if (!datas)
//         return (NULL);
//     i = 0;
//     j = 0;
//     while (str[j])
//     {
//         if (str[j] == ' ')
//             j++;
//         datas[i] = atoi(&str[j]);
//         i++;
//         while (str[j] && str[j] != ' ')
//             j++;
//     }
//     free(str);
//     return (datas);
// }
