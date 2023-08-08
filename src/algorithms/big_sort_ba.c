/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_ba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:19:56 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 13:06:37 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_from_a(t_stack *stack_a,
				t_stack *stack_b, t_score *min_score)
{
	find_cheapest(stack_a, stack_b, min_score);
	move_cheapest(stack_a, stack_b, min_score);
	pb(stack_a, stack_b);
	set_null_score(min_score);
}

void	find_cheapest(t_stack *stack_a, t_stack *stack_b, t_score *min_score)
{
	int		pos_a;
	t_score	current_elem_score;
	t_node	*tmp_node_a;

	pos_a = 1;
	set_null_score(&current_elem_score);
	tmp_node_a = stack_a->top;
	while (tmp_node_a)
	{
		current_elem_score.actions[ra_count] = pos_a - 1;
		current_elem_score.actions[rra_count] = (stack_a->size - pos_a) + 1;
		count_place_in_b(tmp_node_a->data, stack_b, &current_elem_score);
		count_min_steps(&current_elem_score);
		if ((tmp_node_a == stack_a->top)
			|| (current_elem_score.total_score < min_score->total_score))
			copy_score(&current_elem_score, min_score);
		if (min_score->total_score <= 1)
			break ;
		set_null_score(&current_elem_score);
		tmp_node_a = tmp_node_a->next;
		pos_a++;
	}
}
