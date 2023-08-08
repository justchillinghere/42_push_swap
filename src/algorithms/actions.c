/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:41:07 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 11:41:08 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_action(t_stack *stack_a, t_stack *stack_b, int action_index)
{
	if (action_index == ra_count)
		ra(stack_a);
	else if (action_index == rb_count)
		rb(stack_b);
	else if (action_index == rr_count)
		rr(stack_a, stack_b);
	else if (action_index == rra_count)
		rra(stack_a);
	else if (action_index == rrb_count)
		rrb(stack_b);
	else
		rrr(stack_a, stack_b);
}

void	move_cheapest(t_stack *stack_a, t_stack *stack_b, t_score *score)
{
	int	i;

	i = rrr_count;
	while (i >= 0)
	{
		while (score->actions[i] > 0)
		{
			do_action(stack_a, stack_b, i);
			score->actions[i]--;
			score->total_score--;
		}
		i--;
	}
}
