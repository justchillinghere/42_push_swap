/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:02:05 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/17 20:36:21 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	t_stack *stack_a;

	stack_a = NULL;
	if (argc == 1 || !argv[1][0])
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' '); // convert "1 2 3" to "1", "2", "3"
		argc = count_argc(argv);
	}
	else // if argv is already "1" "2" "3" 
	{
		argv++;
		argc--;
	}
	stack_a = create_stack();
	while (argc)
	{
		push_stack(stack_a, ft_atoi(argv[argc - 1]));
		argc--;
	}
	ft_printf("Before sort:\n");
	print_stack(stack_a);
	ft_printf("–––\n");
	sort_three(stack_a);
	ft_printf("After sort:\n");
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
