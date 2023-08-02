/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:58:00 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/02 14:27:04 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b_from_a(t_stack *stack_a, t_stack *stack_b, t_score *min_score)
{
	find_cheapest(stack_a, stack_b, min_score);
	move_cheapest(stack_a, stack_b, min_score);
	pb(stack_a, stack_b);
	set_null_score(min_score);
}

static void	sort_a_from_b(t_stack *stack_a, t_stack *stack_b, t_score *min_score)
{
	count_place_in_stack(stack_b->top->data, stack_a, min_score);
	transform_rotations_ba(min_score);
	move_cheapest(stack_a, stack_b, min_score);
	pa(stack_a, stack_b);
	set_null_score(min_score);
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
