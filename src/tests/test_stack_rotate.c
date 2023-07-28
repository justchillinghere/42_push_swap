/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:41:26 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/24 23:29:24 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test_push_swap.h"

// Initially, stack is 50->40->30->20->10
static void	setup_stack(void)
{
	stack = create_stack();
	int i = 0;
	while (i < 5)
		push_stack(stack, (++i) * 10);
}

static void	teardown_stack(void)
{
	free_stack(stack);
}

TestSuite(stack_rotate, .init=setup_stack, .fini=teardown_stack);

Test(stack_rotate, test_rotate)
{
	rotate_stack(stack);
	cr_assert(eq(stack->top->data, 40), "Rotate failed. Top pointer is incorrect");
	cr_assert(eq(stack->bottom->data, 50), "Rotate failed. Bottom pointer is incorrect");
	
	rotate_stack(stack);
	cr_assert(eq(stack->top->data, 30), "Rotate failed. Top pointer is incorrect");
	cr_assert(eq(stack->bottom->data, 40), "Rotate failed. Bottom pointer is incorrect");
}

Test(stack_rotate, test_reverse_rotate)
{
	reverse_rotate_stack(stack);
	cr_assert(eq(stack->top->data, 10), "Reverse Rotate failed. Top pointer is incorrect");
	cr_assert(eq(stack->bottom->data, 20), "Reverse Rotate failed. Bottom pointer is incorrect");
	
	reverse_rotate_stack(stack);
	cr_assert(eq(stack->top->data, 20), "Reverse Rotate failed. Top pointer is incorrect");
	cr_assert(eq(stack->bottom->data, 30), "Reverse Rotate failed. Bottom pointer is incorrect");
}


Test(stack_rotate, test_rotate_min_max)
{
	rotate_stack(stack);
	cr_assert(eq(stack->max->data, 50), "Reverse Rotate failed. Top pointer is incorrect");
	cr_assert(eq(stack->min->data, 10), "Reverse Rotate failed. Bottom pointer is incorrect");
	
	rotate_stack(stack);
	cr_assert(eq(stack->max->data, 50), "Reverse Rotate failed. Top pointer is incorrect");
	cr_assert(eq(stack->min->data, 10), "Reverse Rotate failed. Bottom pointer is incorrect");
}

Test(stack_rotate, test_rev_rotate_min_max)
{
	reverse_rotate_stack(stack);
	cr_assert(eq(stack->max->data, 50), "Reverse Rotate failed. Top pointer is incorrect");
	cr_assert(eq(stack->min->data, 10), "Reverse Rotate failed. Bottom pointer is incorrect");
	
	reverse_rotate_stack(stack);
	cr_assert(eq(stack->max->data, 50), "Reverse Rotate failed. Top pointer is incorrect");
	cr_assert(eq(stack->min->data, 10), "Reverse Rotate failed. Bottom pointer is incorrect");
}
