/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:02:05 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/06 20:57:36 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	t_stack *stack_a;

	stack_a = create_stack();
	if (argc == 1 || !argv[1][0])
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' '); // convert "1 2 3" to "1", "2", "3"
	else
		argv++;
	while (*argv)
		push_stack(stack_a, ft_atoi(*argv++));
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}