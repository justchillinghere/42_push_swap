/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:10:19 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 11:16:24 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_stack *stack_a)
{
	if (stack_a->size < 3)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else
		sort_big(stack_a);
}

void	sort_three(t_stack *stack)
{
	if (stack->top->data == stack->max->data)
		ra(stack);
	else if (stack->max->data == stack->top->next->data)
		rra(stack);
	if (stack->top->data > stack->top->next->data)
		sa(stack);
}

void	sort_big(t_stack *stack_a)
{
	t_score	*min_score;
	t_stack	*stack_b;

	stack_b = create_stack();
	min_score = malloc(sizeof(t_score));
	set_null_score(min_score);
	pb(stack_a, stack_b);
	if (stack_a->size > 4)
		pb(stack_a, stack_b);
	while (stack_a->size > 3)
		sort_b_from_a(stack_a, stack_b, min_score);
	sort_three(stack_a);
	while (stack_b->size > 0)
		sort_a_from_b(stack_a, stack_b, min_score);
	count_min_to_top(min_score, stack_a);
	transform_rotations_ba(min_score);
	move_cheapest(stack_a, stack_b, min_score);
	free(min_score);
	free_stack(stack_b);
}
