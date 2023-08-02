/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:31:58 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/01 15:41:53 by luchitel         ###   ########.fr       */
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
	int i;
	
	i = rrr_count;
	while (i >= 0)
	{
		while (score->actions[i] > 0)
		{
			do_action(stack_a, stack_b, i);
			score->actions[i]--;
		}
		i--;
	}
}

void	count_min_to_top(t_score *score, t_stack *stack)
{
	int	elem_pos;

	elem_pos = find_stack_min_pos(stack);
	score->actions[ra_count] = elem_pos - 1;
	score->actions[rra_count] = (stack->size - elem_pos) + 1;
}

int	find_stack_min_pos(t_stack *stack)
{
	if (stack->min == stack->top)
		return (1);
	else if (stack->min == stack->bottom)
		return (stack->size);
	else
		return (stack->max_pos + 1);
}

void transform_rotations_ba(t_score *score)
{
	if (score->actions[ra_count] > score->actions[rra_count])
		score->actions[ra_count] = 0;
	else
		score->actions[rra_count] = 0;
}

void	count_place_in_stack(int push_value, t_stack *stack, t_score *current_score)
{
	int	elem_pos;
	t_node	*tmp_node;

	tmp_node = stack->min;
	// elem_pos is min now
	elem_pos = find_stack_min_pos(stack);
	if (!(push_value > stack->max->data) && !(push_value < stack->min->data))
	{
		while (push_value > tmp_node->data)
		{
			if (!tmp_node->next)
			{
				tmp_node = stack->top;
				elem_pos = 1;
			}
			else
			{
				tmp_node = tmp_node->next;
				elem_pos++;
			}
		}
	}
	current_score->actions[ra_count] = elem_pos - 1;
	current_score->actions[rra_count] = (stack->size - elem_pos) + 1;
}
