/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:26:39 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/31 15:39:22 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			find_cheapest(t_stack *stack_a, t_stack *stack_b, t_score *min_score);
static void		count_place_in_b(int push_value, t_stack *stack_b, t_score *current_score);
static int		find_min_option_index(int options[4]);
static void 	tranform_one_dir_rotate(t_score *, int);
static void		transform_two_dir_rotate(t_score *, int);
static void		count_min_steps(t_score *score);

void	find_cheapest(t_stack *stack_a, t_stack *stack_b, t_score *min_score)
{
	int	pos_a;
	t_score current_elem_score;
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
		// ft_printf("For element %d initial score is:\n", tmp_node_a->data);
		// print_score(&current_elem_score);
		if ((tmp_node_a == stack_a->top) || (min_score->total_score < current_elem_score.total_score))
			copy_score(&current_elem_score, min_score);
		if (min_score->total_score <= 1)
			break;
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

static void tranform_one_dir_rotate(t_score *score, int option_num)
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
	while (score->actions[common_rotate_index - 1] && score->actions[common_rotate_index - 2])
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

static void	transform_two_dir_rotate(t_score *score, int option_num)
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
static void	count_min_steps(t_score *score)
{
	int	options[4];
	int min_opt_index;
	
	options[rr_option] = min(score->actions[ra_count], score->actions[rb_count]) + abs(score->actions[ra_count] - score->actions[rb_count]);
	options[rrr_option] = min(score->actions[rra_count], score->actions[rrb_count]) + abs(score->actions[rra_count] - score->actions[rrb_count]);
	options[ra_rrb_option] = abs(score->actions[ra_count] + score->actions[rrb_count]);
	options[rra_rb_option] = abs(score->actions[rra_count] + score->actions[rb_count]);
	
	min_opt_index = find_min_option_index(options);
	score->total_score = options[min_opt_index];
	if (min_opt_index == rr_option || min_opt_index == rrr_option)
		tranform_one_dir_rotate(score, min_opt_index);
	else
		transform_two_dir_rotate(score, min_opt_index);
}
