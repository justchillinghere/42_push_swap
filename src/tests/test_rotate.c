// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test_rotate.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/07/11 18:44:29 by luchitel          #+#    #+#             */
// /*   Updated: 2023/07/12 12:39:38 by luchitel         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "test_push_swap.h"

// void	test_rotate()
// {
// 	t_stack *stack = create_stack();
//     printf("Stack top: %p\n", stack->top);

// 	int i = 10;
// 	while (i < 60)
// 	{
// 		push_stack(stack, i);
// 		i += 10;
// 	}
//     printf("Stack after pushing: \n");
//     print_stack(stack);

// 	rotate_stack(stack);
// 	printf("Stack after rotation: \n");
//     print_stack(stack);
// 	printf("\n");

// 	printf("Stack top: %d\n", stack->top->data);
// 	printf("Stack bottom: %d\n", stack->bottom->data);

// 	rotate_stack(stack);
// 	printf("Stack after 2nd rotation: \n");
//     print_stack(stack);
// 	printf("\n");

// 	printf("Stack top: %d\n", stack->top->data);
// 	printf("Stack bottom: %d\n", stack->bottom->data);

// 	reverse_rotate_stack(stack);
// 	printf("Stack after reverse rotation: \n");
//     print_stack(stack);
// 	printf("\n");

//     free_stack(stack);
// }

// void	test_reverse_rotate()
// {
// 	t_stack *stack = create_stack();
//     printf("Stack top: %p\n", stack->top);

// 	int i = 10;
// 	while (i < 60)
// 	{
// 		push_stack(stack, i);
// 		i += 10;
// 	}
//     printf("Stack after pushing: \n");
//     print_stack(stack);

// 	reverse_rotate_stack(stack);
// 	printf("Stack after reverse rotation: \n");
//     print_stack(stack);
// 	printf("\n");

// 	printf("Stack top: %d\n", stack->top->data);
// 	printf("Stack bottom: %d\n", stack->bottom->data);

// 	reverse_rotate_stack(stack);
// 	printf("Stack after 2nd reverse rotation: \n");
//     print_stack(stack);
// 	printf("\n");

// 	printf("Stack top: %d\n", stack->top->data);
// 	printf("Stack bottom: %d\n", stack->bottom->data);

//     free_stack(stack);
// }
