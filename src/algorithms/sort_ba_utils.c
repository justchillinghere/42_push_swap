/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ba_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:21:02 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 12:37:16 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_place_in_b(int push_value, t_stack *stack_b,
		t_score *current_score)
{
	int		elem_pos;
	t_node	*tmp_node;

	tmp_node = stack_b->max;
	elem_pos = stack_b->max_pos;
	if ((push_value < stack_b->max->data) && (push_value > stack_b->min->data))
	{
		while (push_value < tmp_node->data)
		{
			if (!tmp_node->next)
			{
				tmp_node = stack_b->top;
				elem_pos = 1;
			}
			else
			{
				tmp_node = tmp_node->next;
				elem_pos++;
			}
		}
	}
	current_score->actions[rb_count] = elem_pos - 1;
	current_score->actions[rrb_count] = (stack_b->size - elem_pos) + 1;
}

int	find_min_option_index(int options[4])
{
	int	min;
	int	i;
	int	min_option_index;

	i = rr_option;
	min_option_index = rr_option;
	min = options[i];
	while (i <= rra_rb_option)
	{
		if (options[i] < min)
		{
			min_option_index = i;
			min = options[i];
		}
		i++;
	}
	return (min_option_index);
}

void	tranform_one_dir_rotate(t_score *score, int option_num)
{
	int	common_rotate_index;
	int	ind_delete;
	int	i;

	common_rotate_index = 0;
	i = -1;
	if (option_num == rr_option)
		common_rotate_index = rr_count;
	else if (option_num == rrr_option)
		common_rotate_index = rrr_count;
	while (score->actions[common_rotate_index - 1]
		&& score->actions[common_rotate_index - 2])
	{
		score->actions[common_rotate_index]++;
		score->actions[common_rotate_index - 1]--;
		score->actions[common_rotate_index - 2]--;
	}
	if (option_num == rr_option)
		ind_delete = rrr_count;
	else
		ind_delete = rr_count;
	while (++i < 3)
		score->actions[ind_delete - i] = 0;
}

void	transform_two_dir_rotate(t_score *score, int option_num)
{
	int	i;
	int	op1;
	int	op2;

	i = 0;
	if (option_num == ra_rrb_option)
	{
		op1 = ra_count;
		op2 = rrb_count;
	}
	else
	{
		op1 = rra_count;
		op2 = rb_count;
	}
	while (i <= rrr_count)
	{
		if (i != op1 && i != op2)
			score->actions[i] = 0;
		i++;
	}
}

/* 
// We have several options of movements: 
1. One-way rotation (rr or rrr) with residual rotations
2. Two-way rotation (rr + rrr) for two stacks
In this function I count sum of steps of rotation and find the minimal one
Then I form steps according to the optimal strategy 
*/
void	count_min_steps(t_score *score)
{
	int	options[4];
	int	min_opt_index;

	options[rr_option] = min(score->actions[ra_count], score->actions[rb_count])
		+ abs(score->actions[ra_count] - score->actions[rb_count]);
	options[rrr_option] = min(score->actions[rra_count],
			score->actions[rrb_count]) + abs(score->actions[rra_count]
			- score->actions[rrb_count]);
	options[ra_rrb_option] = abs(score->actions[ra_count]
			+ score->actions[rrb_count]);
	options[rra_rb_option] = abs(score->actions[rra_count]
			+ score->actions[rb_count]);
	min_opt_index = find_min_option_index(options);
	score->total_score = options[min_opt_index];
	if (min_opt_index == rr_option || min_opt_index == rrr_option)
		tranform_one_dir_rotate(score, min_opt_index);
	else
		transform_two_dir_rotate(score, min_opt_index);
}
