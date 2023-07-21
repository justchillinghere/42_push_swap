/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_impl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:08:05 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/21 16:03:07 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test_push_swap.h"

static void	setup_stack(void)
{
	stack = create_stack();
}

static void	teardown_stack(void)
{
	free_stack(stack);
}

TestSuite(stack_implementation, .init=setup_stack, .fini=teardown_stack);

Test(stack_implementation, test_push, .description="Testing push operation on stack")
{
	push_stack(stack, 10);
	cr_assert(eq(stack->top->data, 10), "Push failed. Top pointer is incorrect");
	cr_assert(eq(stack->bottom->data, 10), "Push failed. Bottom pointer is incorrect");
	
	push_stack(stack, 20);
	cr_assert(eq(stack->top->data, 20), "Push failed. Top pointer is incorrect");
	cr_assert(eq(stack->bottom->data, 10), "Push failed. Bottom pointer is incorrect");
	
	push_stack(stack, 30);
	cr_assert(eq(stack->top->data, 30), "Push failed. Top pointer is incorrect");
	cr_assert(eq(stack->bottom->data, 10), "Push failed. Bottom pointer is incorrect");
}

Test(stack_implementation, test_pop, .description="Testing pop operation on stack")
{
	push_stack(stack, 10);
	push_stack(stack, 20);
	push_stack(stack, 30);

	int val = pop_stack(stack);

	cr_assert(eq(val, 30), "Pop incorrect value");
	cr_assert(eq(stack->top->data, 20), "Incorrect top value after pop");
	cr_assert(eq(stack->bottom->data, 10), "Incorrect top value after pop");
	
	val = pop_stack(stack);
	cr_assert(eq(val, 20), "Pop incorrect value");
	cr_assert(eq(stack->top->data, 10), "Incorrect top value after pop");
	cr_assert(eq(stack->bottom->data, 10), "Incorrect top value after pop");
}

Test(stack_implementation, test_size, .description="Testing size operation on stack")
{
	push_stack(stack, 10);
	push_stack(stack, 20);
	push_stack(stack, 30);

	cr_assert(eq(get_stack_size(stack), 3), "Return stack size is incorect");
}

Test(stack_implementation, test_push_max,
	 .description="Testing if max value correct in push operation on stack")
{
	push_stack(stack, 10);
	cr_assert(eq(stack->max, 10), "Max has been set incorrectly");
	cr_assert(eq(stack->min, 10), "Min has been set incorrectly");
	push_stack(stack, 20);
	cr_assert(eq(stack->max, 20), "Max has been set incorrectly");
	cr_assert(eq(stack->min, 10), "Min has been set incorrectly");
	push_stack(stack, 30);
	cr_assert(eq(stack->max, 30), "Max has been set incorrectly");
	cr_assert(eq(stack->min, 10), "Min has been set incorrectly");
	push_stack(stack, 0);
	cr_assert(eq(stack->max, 30), "Max has been set incorrectly");
	cr_assert(eq(stack->min, 0), "Min has been set incorrectly");
}

// Test(stack_implementation, test_pop_min, .description="Testing pop operation on stack")
// {
// 	push_stack(stack, 10);
// 	push_stack(stack, 20);
// 	push_stack(stack, 30);

// 	int val = pop_stack(stack);

// 	cr_assert(eq(val, 30), "Pop incorrect value");
// 	cr_assert(eq(stack->top->data, 20), "Incorrect top value after pop");
// 	cr_assert(eq(stack->bottom->data, 10), "Incorrect top value after pop");
	
// 	val = pop_stack(stack);
// 	cr_assert(eq(val, 20), "Pop incorrect value");
// 	cr_assert(eq(stack->top->data, 10), "Incorrect top value after pop");
// 	cr_assert(eq(stack->bottom->data, 10), "Incorrect top value after pop");
// }
