/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:43:23 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/02 19:37:30 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_has_value(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size && size != 0)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	count_argc(char **argv)
{
	int	 i;

	i = 0;
	while(argv[i])
		i++;
	return (i);
}

int	is_format_correct(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
			{
				// ft_printf("HERE: |%c| |%s %d|\n", argv[i][j], argv[i], j);
				return (ERROR);
			}
			if (argv[i][j] == '-' && !(j == 0 && argv[i][1] && ft_isdigit(argv[i][1])))
			{
				// ft_printf("HERE: |%c| |%s %d|\n", argv[i][j], argv[i], j);
				return (ERROR);
			}
			j++;
		}
		if (!argv[i][0])
		{
			// ft_printf("HERE: |%c| |%s %d|\n", argv[i][j], argv[i], j);
			return (ERROR);
		}
		i++;
		j = 0;
	}
	return (OK);
}
