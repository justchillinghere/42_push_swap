/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:35:44 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/24 23:06:44 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_pushed_val(t_stack *stack)
{
	if (stack->top->data > stack->max->data)
		stack->max = stack->top;
	else if (stack->top->data < stack->min->data)
		stack->min = stack->top;
}

void	check_popped_val(t_stack *new_stack, int popped_val)
{
	if (is_stack_empty(new_stack))
		return;
	if (popped_val == new_stack->max->data)
		new_stack->max = get_max_stack_value(new_stack);
	else if (popped_val == new_stack->min->data)
		new_stack->min = get_min_stack_value(new_stack);
}

t_node	*get_max_stack_value(t_stack *stack)
{
	t_node	*max_node;
	t_node	*tmp_node;

	max_node = stack->top;
	tmp_node = stack->top;
	while (tmp_node)
	{
		if (tmp_node->data > max_node->data)
			max_node = tmp_node;
		tmp_node = tmp_node->next;
	}
	return (max_node);
}

t_node	*get_min_stack_value(t_stack *stack)
{
	t_node	*min_node;
	t_node	*tmp_node;

	min_node = stack->top;
	tmp_node = stack->top;
	while (tmp_node)
	{
		if (tmp_node->data < min_node->data)
			min_node = tmp_node;
		tmp_node = tmp_node->next;
	}
	return (min_node);
}
