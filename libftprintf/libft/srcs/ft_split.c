/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:29:18 by luchitel          #+#    #+#             */
/*   Updated: 2023/03/07 17:10:04 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_found(char const to_find, char c)
{
	if (c == to_find)
		return (1);
	return (0);
}

int	words_count(char const *str, char c)
{
	int	i;
	int	words_count;

	i = 0;
	words_count = 0;
	while (str[i])
	{
		while (is_found(str[i], c) && str[i])
			i++;
		if (!is_found(str[i], c) && str[i])
		{
			words_count++;
			while (!is_found(str[i], c) && str[i])
				i++;
		}
	}
	return (words_count);
}

char	*get_word(char const *str, int begin, int end)
{
	char	*out;
	int		i;

	out = (char *)malloc(sizeof(char) * (end - begin) + 1);
	i = 0;
	while (begin < end)
	{
		out[i] = str[begin];
		begin++;
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		i;
	int		word_begin;
	int		words;
	int		index;

	i = 0;
	word_begin = 0;
	index = 0;
	words = words_count(str, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);
	while (str[i] && index < words)
	{
		while (is_found(str[i], c) && str[i])
			i++;
		word_begin = i;
		while (!is_found(str[i], c) && str[i])
			i++;
		result[index] = get_word(str, word_begin, i);
		index++;
	}
	result[index] = 0;
	return (result);
}
