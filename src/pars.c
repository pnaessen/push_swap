/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:14:13 by pnaessen          #+#    #+#             */
/*   Updated: 2025/01/10 10:02:42 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		str = skip_whitespace(str);
		if (*str == '\0')
			break ;
		str = skip_word(str);
		count++;
	}
	return (count);
}

const char	*skip_word(const char *str)
{
	while (*str && *str != ' ' && *str != '\t')
		str++;
	return (str);
}

char	*strjoin(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*str;
	int		len;

	len = calculate_length(argc, argv);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			str[k++] = argv[i][j++];
		if (i < argc - 1)
			str[k++] = ' ';
		i++;
	}
	str[k] = '\0';
	return (str);
}

char	*allocate_word(const char *start, const char *end)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = end - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**split_args(const char *str, int *count)
{
	char		**res;
	int			i;
	const char	*start;

	*count = count_words(str);
	if (is_valid_number(str) == 0)
		return (NULL);
	res = malloc(sizeof(char *) * (*count + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*str)
	{
		str = skip_whitespace(str);
		if (*str == '\0')
			break ;
		start = str;
		str = skip_word(str);
		res[i] = allocate_word(start, str);
		if (!res[i])
			return (free_all(res, i));
		i++;
	}
	res[i] = NULL;
	return (res);
}
