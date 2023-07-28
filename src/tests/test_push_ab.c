/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:55:12 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/24 18:33:16 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

static t_stack *b_stack;

static void	setup_stack(void)
{
	stack = create_stack();
	b_stack = create_stack();
	push_stack(stack, 10);
	push_stack(stack, 20);
	push_stack(stack, 30);
}

static void	teardown_stack(void)
{
	free_stack(stack);
	free_stack(b_stack);
}

TestSuite(push_ab, .init=setup_stack, .fini=teardown_stack);

Test(push_ab, push_from_stack_to_stack)
{
	push_from_stack_to_stack(stack, b_stack);
	cr_assert(eq(b_stack->top->data, 30), "Pushed 1st time from stack to stack incorrectly");
	cr_assert(eq(stack->top->data, 20), "Pushed 1st time from stack to stack incorrectly");

	cr_assert(eq(b_stack->max->data, 30));
	cr_assert(eq(stack->max->data, 20));

	cr_assert(eq(b_stack->min->data, 30));
	cr_assert(eq(stack->min->data, 10));

	cr_assert(eq(stack->size, 2));
	cr_assert(eq(b_stack->size, 1));

	push_from_stack_to_stack(stack, b_stack); // 10 <--> 20 30

	cr_assert(eq(b_stack->top->data, 20), "Pushed 1st time from stack to stack incorrectly");
	cr_assert(eq(stack->top->data, 10), "Pushed 1st time from stack to stack incorrectly");

	cr_assert(eq(b_stack->max->data, 30));
	cr_assert(eq(stack->max->data, 10));

	cr_assert(eq(b_stack->min->data, 20));
	cr_assert(eq(stack->min->data, 10));

	cr_assert(eq(stack->size, 1));
	cr_assert(eq(b_stack->size, 2));
}
