// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test_stack_swap.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/07/07 17:45:40 by luchitel          #+#    #+#             */
// /*   Updated: 2023/07/11 13:46:45 by luchitel         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "test_push_swap.h"

// void	test_swap()
// {
//     t_stack *stack = create_stack();
//     printf("Stack top: %p\n", stack->top);

// 	int i = 10;
// 	while (i < 60)
// 	{
// 		push_stack(stack, i);
// 		i += 10;
// 	}
//     printf("Stack after pushing: \n");
//     print_stack(stack);

// 	swap_stack(stack);
// 	printf("Stack after swapping: \n");
//     print_stack(stack);

//     // Test free_stack function
//     free_stack(stack);
//     printf("Stack after freeing: \n");
//     print_stack(stack);
// }