/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:35:44 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/21 15:31:04 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_pushed_val(t_stack *new_stack, int pushed_val)
{
	if (pushed_val > new_stack->max)
		new_stack->max = pushed_val;
	else if (pushed_val < new_stack->min)
		new_stack->min = pushed_val;
}

void	check_popped_val(t_stack *new_stack, int popped_val)
{
	if (is_stack_empty(new_stack))
		return;
	if (popped_val == new_stack->max)
		new_stack->max = get_max_stack_value(new_stack);
	else if (popped_val == new_stack->min)
		new_stack->min = get_min_stack_value(new_stack);
}

int	get_max_stack_value(t_stack *stack)
{
	int	max_value;
	t_node	*tmp_node;

	max_value = 0;
	tmp_node = stack->top;
	while (tmp_node)
	{
		if (tmp_node->data > max_value)
			max_value = tmp_node->data;
		tmp_node = tmp_node->next;
	}
	return (max_value);
}

int	get_min_stack_value(t_stack *stack)
{
	int	min_value;
	t_node	*tmp_node;

	min_value = 0;
	tmp_node = stack->top;
	while (tmp_node)
	{
		if (tmp_node->data < min_value)
			min_value = tmp_node->data;
		tmp_node = tmp_node->next;
	}
	return (min_value);
}
