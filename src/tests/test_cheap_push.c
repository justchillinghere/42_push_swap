// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test_cheap_push.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/07/27 18:19:20 by luchitel          #+#    #+#             */
// /*   Updated: 2023/08/02 14:02:17 by luchitel         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "test_push_swap.h"

// static t_stack *stack_a;
// static t_stack *stack_b;

// static void	setup_stack_initial(void)
// {
// 	stack_a = create_stack();
// 	stack_b = create_stack();
// 	push_stack(stack_a, 100);
// 	push_stack(stack_a, 4);
// 	push_stack(stack_a, 5);
// 	push_stack(stack_a, 8);
// }

// static void	teardown_stack(void)
// {
// 	free_stack(stack_a);
// 	free_stack(stack_b);
// 	ft_printf("Freed\n");
// }

// TestSuite(cheap_algo, .init=setup_stack_initial, .fini=teardown_stack);

// Test(cheap_algo, test_cheap)
// {
// 	ft_printf("Stack A before:\n");
// 	print_stack(stack_a);
// 	ft_printf("\n--------\n");
// 	sort_big(stack_a);
// 	ft_printf("Stack A after:\n");
// 	print_stack(stack_a);
// 	ft_printf("\n--------\n");
// }

// // static void	setup_stack_case_1(void)
// // {
// // 	stack_a = create_stack();
// // 	stack_b = create_stack();

// // 	push_stack(stack_a, 8);
// // 	push_stack(stack_a, 4);
// // 	push_stack(stack_a, 9);
// // 	push_stack(stack_a, 3);
// // 	push_stack(stack_a, 6);

// // 	push_stack(stack_b, 2);
// // 	push_stack(stack_b, 5);
// // 	push_stack(stack_b, 7);
// // 	push_stack(stack_b, 1);
// // }

// // TestSuite(cheap_algo_cases, .init=setup_stack_case_1, .fini=teardown_stack);

// // Test(cheap_algo_cases, case_1)
// // {
// // 	t_score *min_score;


// 	// ft_printf("Stack A before:\n");
// 	// print_stack(stack_a);
// 	// ft_printf("\n--------\n");
// 	// ft_printf("Stack B before:\n");
// 	// print_stack(stack_b);
// 	// ft_printf("\n--------\n");
// 	// min_score = malloc(sizeof(t_score));
// 	// set_null_score(min_score);
	
// 	// find_cheapest(stack_a, stack_b, min_score);
// 	// print_score(min_score);
// 	// move_cheapest(stack_a, stack_b, min_score);
// 	// print_score(min_score);

// 	// ft_printf("Stack A after:\n");
// 	// print_stack(stack_a);
// 	// ft_printf("\n--------\n");
// 	// ft_printf("Stack B:\n");
// 	// print_stack(stack_b);
// 	// ft_printf("\n--------\n");
// 	// free(min_score);
// // }
