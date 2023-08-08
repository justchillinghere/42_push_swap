/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:04:31 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 11:05:16 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = num;
	node->next = NULL;
	return (node);
}

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	new_stack->max = NULL;
	new_stack->min = NULL;
	new_stack->size = 0;
	new_stack->max_pos = 0;
	return (new_stack);
}

int	is_stack_empty(t_stack *stack)
{
	if (!stack->top)
		return (1);
	return (0);
}

void	free_stack(t_stack *stack)
{
	while (!is_stack_empty(stack))
		pop_stack(stack);
}
