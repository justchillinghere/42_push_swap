/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:08:05 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/14 18:04:11 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test_push_swap.h"

Test(stack_implementation, stack_pushing) {

	t_stack *stack = create_stack();
	t_node	*tmp_node;
	int num_of_values = 5;
	int	i = 0;
	int node_values[] = {10, 20, 30, 40, 50};

	while (i < num_of_values)
		push_stack(stack, node_values[i++]);

	i = num_of_values;
	tmp_node = stack->top;

	while (i && tmp_node)
	{
		cr_assert(eq(node_values[i - 1], tmp_node->data), "Failed while validating stack push function");
		tmp_node = tmp_node->next;
		i--;
	}
	cr_assert(eq(node_values[0], stack->bottom->data), "Bottom has been set incorrectly");
	cr_assert(eq(node_values[num_of_values - 1], stack->top->data), "Top has been set incorrectly");
	free_stack(stack);
	cr_assert(zero(stack->top), "Stack was not freed");
}

// int main()
// {
	
	
// 	// ft_printf("### TEST 1 ###\n");
// 	// test_stack_impl();
// 	// // ft_printf("### TEST 2 ###\n");
// 	// // test_swap();
// 	// // ft_printf("### TEST 3 ###\n");
// 	// // test_rotate();
// 	// ft_printf("### TEST 4 ###\n");
// 	// test_reverse_rotate();



//     return 0;
// }