/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:14:13 by pnaessen          #+#    #+#             */
/*   Updated: 2024/12/20 17:18:21 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strjoin(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*str;
	int		len;

	i = 1;
	j = 0;
	k = 0;
	len = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '"')
				return (0);
			j++;
			len++;
		}
		i++;
	}
	str = malloc(sizeof(char) * (argc + len));
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
		str[k++] = ' ';
		i++;
	}
	str[k] = '\0';
	return (str);
}
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	*get_datas(int argc, char **argv) // split a chaque diff de 0 a 9
{
	int i;
	int j;
	int *datas;
	char *str;

	i = 1;
	j = 0;
	str = strjoin(argc, argv);
	if (!str)
		return (NULL);
	while (str[j])
	{
		if (str[j] == ' ')
			i++;
		j++;
	}
	datas = malloc(sizeof(int) * i);
	if (!datas)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
	{
		if (!(str[j] >= '0' && str[j] <= '9') || str[j] != '-')
			j++;
		datas[i] = ft_atoi(&str[j]);
		printf("datas[i] = %d\n", datas[i]);
		i++;
		while (str[j] && ((str[j] >= '0' && str[j] <= '9') || str[j] == '-'))
			j++;
	}
	free(str);
	return (datas);
}
