/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:03:40 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/17 18:07:30 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

TestSuite(stack_swap, .init=setup_stack, .fini=teardown_stack);

Test(stack_swap, stack_swap)
{
	swap_stack(stack);
	cr_assert(eq(stack->top->data, 40), "Swap failed. Top pointer is incorrect");
	cr_assert(eq(stack->top->next->data, 50), "Swap failed. Second node is incorrect");
	cr_assert(eq(stack->bottom->data, 10), "Swap failed. Bottom pointer is incorrect");
}
