/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:58:00 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 11:22:13 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_from_b(t_stack *stack_a,
				t_stack *stack_b, t_score *min_score)
{
	count_place_in_stack(stack_b->top->data, stack_a, min_score);
	transform_rotations_ba(min_score);
	move_cheapest(stack_a, stack_b, min_score);
	pa(stack_a, stack_b);
	set_null_score(min_score);
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

void	transform_rotations_ba(t_score *score)
{
	if (score->actions[ra_count] > score->actions[rra_count])
		score->actions[ra_count] = 0;
	else
		score->actions[rra_count] = 0;
}

void	count_place_in_stack(int push_value,
			t_stack *stack,
			t_score *current_score)
{
	int		elem_pos;
	t_node	*tmp_node;

	tmp_node = stack->min;
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
