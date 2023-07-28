/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:26:39 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/28 15:36:36 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			find_cheapest(t_stack *stack_a, t_stack *stack_b, t_score *min_score);
static void		count_place_in_b(int push_value, t_stack *stack_b, t_score *current_score);
static int		find_min_option_index(int options[4]);
static void 	tranform_one_dir_rotate(int *actions, int option_num);
static void		transform_two_dir_rotate(int *actions, int option_num);
static void 	form_optimal_actions(t_score *score, int option_num);
static void		count_min_steps(t_score *score);

void	find_cheapest(t_stack *stack_a, t_stack *stack_b, t_score *min_score)
{
	int	pos_a;
	t_score current_elem_score;
	t_node	*tmp_node_a;

	if (is_stack_empty(stack_a))
		return;

	pos_a = 0;
	set_null_score(&current_elem_score);
	tmp_node_a = stack_a->top;
	while (tmp_node_a && min_score->total_score > 1)
	{
		current_elem_score.actions[ra_count] = pos_a;
		current_elem_score.actions[rra_count] = (stack_a->size - pos_a) + 1;
		count_place_in_b(tmp_node_a->data, stack_b, &current_elem_score);
		count_min_steps(&current_elem_score);
		if ((tmp_node_a == stack_a->top) || (min_score->total_score < current_elem_score.total_score))
			copy_score(&current_elem_score, min_score);
		set_null_score(&current_elem_score);
		tmp_node_a = tmp_node_a->next;
		pos_a++;
	}
}

static void	count_place_in_b(int push_value, t_stack *stack_b, t_score *current_score)
{
	int	elem_pos;
	t_node	*tmp_node;

	tmp_node = stack_b->max;
	elem_pos = stack_b->max_pos;
	if (!(push_value > stack_b->max->data) && !(push_value < stack_b->min->data))
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

static int	find_min_option_index(int options[4])
{
	int	min;
	int	i;
	int min_option_index;

	i = 0;
	min_option_index = i;
	min = options[i++];
	while (i < 4)
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

static void tranform_one_dir_rotate(int *actions, int option_num)
{
	int	common_rotate_index;
	int	ind_delete;
	int	i;

	i = -1;
	common_rotate_index = 0;
	if (option_num == rr_option)
		common_rotate_index = rr_count;
	else if (option_num == rrr_option)
		common_rotate_index = rrr_count;
	while (actions[common_rotate_index - 1] && actions[common_rotate_index - 2])
	{
		actions[common_rotate_index]++;
		actions[common_rotate_index - 1]--;
		actions[common_rotate_index - 2]--;
	}
	if (common_rotate_index == rr_option)
		ind_delete = rrr_option;
	else
		ind_delete = rr_option;
	while (++i < 3)
		actions[ind_delete - i] = 0;
}

static void	transform_two_dir_rotate(int *actions, int option_num)
{
	int i;
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
		if (i != op1 || i != op2)
			actions[i++] = 0;
	}
}

static void form_optimal_actions(t_score *score, int	option_num)
{
	score->total_score = option_num;
	if (option_num == rr_option || option_num == rrr_option)
		tranform_one_dir_rotate(score->actions, option_num);
	else
		transform_two_dir_rotate(score->actions, option_num);
}

static void	count_min_steps(t_score *score)
{
	int	options[4];
	
	options[rr_option] = min(score->actions[ra_count], score->actions[rb_count]) + abs(score->actions[ra_count] - score->actions[rb_count]);
	options[rrr_option] = min(score->actions[rra_count], score->actions[rrb_count]) + abs(score->actions[rra_count] - score->actions[rrb_count]);
	options[ra_rrb_option] = abs(score->actions[ra_count] + score->actions[rrb_count]);
	options[rra_rb_option] = abs(score->actions[rra_count] + score->actions[rb_count]);
	form_optimal_actions(score, find_min_option_index(options));
}
