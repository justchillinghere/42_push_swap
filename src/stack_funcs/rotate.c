/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:10:20 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/12 12:40:21 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack)
{
	t_node	*new_bottom;

	if (is_stack_empty(stack) || stack->top->next == NULL)
		return;
	new_bottom = stack->top;
	stack->top = stack->top->next;
	
	stack->bottom->next = new_bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->next = NULL;
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*new_top;
	t_node	*current_node;

	if (is_stack_empty(stack) || stack->top->next == NULL)
		return;
	current_node = stack->top;
	while (current_node->next->next)
		current_node = current_node->next;
	new_top = current_node->next;
	current_node->next = NULL;
	stack->bottom = current_node;
	new_top->next = stack->top;
	stack->top = new_top;
}