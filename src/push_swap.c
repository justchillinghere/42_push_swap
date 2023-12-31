/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:02:05 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 16:31:16 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*values_array;

	stack_a = NULL;
	argv = get_correct_input_str(&argc, argv);
	values_array = get_unique_values_array(argc, argv);
	stack_a = form_init_stack(values_array, argc);
	free(values_array);
	if (stack_a->size > 1 && !is_stack_sorted(stack_a))
		start_sort(stack_a);
	free_stack(stack_a);
	return (0);
}
