/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cheap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:19:20 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/07 17:28:48 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

static t_stack *stack_a;
static t_stack *stack_b;

// static void	setup_stack_initial(void)
// {
// 	stack_a = create_stack();
// 	stack_b = create_stack();
// 	push_stack(stack_a, 100);
// 	push_stack(stack_a, 4);
// 	push_stack(stack_a, 5);
// 	push_stack(stack_a, 8);
// }

static void	teardown_stack(void)
{
	free_stack(stack_a);
	free_stack(stack_b);
	ft_printf("Freed\n");
}

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

static void	setup_stack_case_1(void)
{
	stack_a = create_stack();
	stack_b = create_stack();

	push_stack(stack_a, -3);
	push_stack(stack_a, 250);
	push_stack(stack_a, 377);
	push_stack(stack_a, 630);
	push_stack(stack_a, 241);
	push_stack(stack_a, -790);
	push_stack(stack_a, 361);
	push_stack(stack_a, 484);
	push_stack(stack_a, 92);
	push_stack(stack_a, -181);
	push_stack(stack_a, -948);
	push_stack(stack_a, -53);
	push_stack(stack_a, 708);
	push_stack(stack_a, 706);
	push_stack(stack_a, 443);
	push_stack(stack_a, 571);
	push_stack(stack_a, -460);
	push_stack(stack_a, 946);
	push_stack(stack_a, -207);
	push_stack(stack_a, 558);
	push_stack(stack_a, 425);
	push_stack(stack_a, 165);
	push_stack(stack_a, -351);
	push_stack(stack_a, -355);
	push_stack(stack_a, -101);

	push_stack(stack_b, 527);
	push_stack(stack_b, 645);
	push_stack(stack_b, -512);
	push_stack(stack_b, 9);
	push_stack(stack_b, 151);
}

TestSuite(cheap_algo_cases, .init=setup_stack_case_1, .fini=teardown_stack);

Test(cheap_algo_cases, case_1)
{
	t_score *min_score;


	ft_printf("Stack A before:\n");
	print_stack(stack_a);
	ft_printf("\n--------\n");
	ft_printf("Stack B before:\n");
	print_stack(stack_b);
	ft_printf("\n--------\n");
	min_score = malloc(sizeof(t_score));
	set_null_score(min_score);
	
	find_cheapest(stack_a, stack_b, min_score);
	print_score(min_score);
	move_cheapest(stack_a, stack_b, min_score);
	print_score(min_score);

	ft_printf("Stack A after:\n");
	print_stack(stack_a);
	ft_printf("\n--------\n");
	ft_printf("Stack B:\n");
	print_stack(stack_b);
	ft_printf("\n--------\n");
	free(min_score);
}
