/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:10:10 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/02 19:35:47 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **get_correct_input_str(int *argc, char **argv)
{	
	if (*argc == 1 || !argv[1][0])
		ft_error();
	if (*argc == 2)
	{
		argv = ft_split(argv[1], ' '); // convert "1 2 3" to "1", "2", "3"
		*argc = count_argc(argv);
	}
	else // if argv is already "1" "2" "3" 
	{
		argv++;
		(*argc)--;
	}
	// ft_printf("HERE\n");
	if (!is_format_correct(*argc, argv))
		ft_error();
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
	int* 	arr;
	int		i;
	int		value;
	int		len;

	i = 0;
	arr = (int*)malloc(argc * sizeof(int));
	if (!arr)
		ft_error();
	while (i < argc)
	{
		// ft_printf("%s\n", argv[i]);
		value = ft_atoi(argv[i]);
		len = ft_strlen(argv[i]);
		if ( ft_strncmp(argv[i], ft_itoa(value), len) != 0 || arr_has_value(arr, i, value))
		{
			free(arr);
			ft_error();
		}
		arr[i] = value;
		i++;
	}
	return (arr);
}
