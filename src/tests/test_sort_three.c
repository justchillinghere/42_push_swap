/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:37:05 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/17 21:37:15 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

// Initially, stack is 50->40->30->20->10
static void	setup_stack(void)
{
	stack = create_stack();
	push_stack(stack, 100);
	push_stack(stack, -1);
	push_stack(stack, 30);
}

static void	teardown_stack(void)
{
	free_stack(stack);
}

TestSuite(sort_three, .init=setup_stack, .fini=teardown_stack);

Test(sort_three, sort_three)
{
	sort_three(stack);
	cr_assert(eq(stack->top->data, -1), "Sort 3 failed. Top pointer is incorrect");
	cr_assert(eq(stack->top->next->data, 30), "Sort 3 failed. Second node is incorrect");
	cr_assert(eq(stack->bottom->data, 100), "Swap failed. Bottom pointer is incorrect");
}
