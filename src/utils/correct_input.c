/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:10:10 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 17:26:36 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_correct_argv_on_heap(int *argc, char **argv)
{
	int		i;
	char	**heap_argv;

	i = 0;
	argv++;
	(*argc)--;
	heap_argv = (char **) malloc((*argc + 1) * sizeof(char *));
	if (!heap_argv)
		ft_error();
	while (i < *argc)
	{
		heap_argv[i] = ft_strdup(argv[i]);
		i++;
	}
	argv[i] = 0;
	return (heap_argv);
}

char	**get_correct_input_str(int *argc, char **argv)
{	
	if (*argc == 1 || !argv[1][0])
		exit(0);
	if (*argc == 2 && ft_strlen(argv[1]) > 1)
	{
		argv = ft_split(argv[1], ' ');
		*argc = count_argc(argv);
	}
	else
	{
		argv = get_correct_argv_on_heap(argc, argv);
		*argc = count_argc(argv);
	}
	if (!is_format_correct(*argc, argv))
	{
		free_heap_argv(argv, *argc);
		ft_error();
	}
	return (argv);
}

t_stack	*form_init_stack(int *arr, int argc)
{
	t_stack	*stack_a;

	stack_a = create_stack();
	if (!stack_a)
		ft_error();
	while (argc)
	{
		push_stack(stack_a, arr[argc - 1]);
		argc--;
	}
	return (stack_a);
}

int	*get_unique_values_array(int argc, char **argv)
{
	int		*arr;
	int		i;
	int		value;
	char	*value_str;

	i = 0;
	arr = (int *) malloc(argc * sizeof(int));
	if (!arr)
		ft_error();
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		value_str = ft_itoa(value);
		if (ft_strncmp(argv[i], value_str, ft_strlen(argv[i])) != 0
			|| arr_has_value(arr, i, value))
			free_data_error_in_value(arr, value_str, argv, argc);
		free(value_str);
		arr[i++] = value;
	}
	free_heap_argv(argv, argc);
	return (arr);
}
