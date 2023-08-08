/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:42:25 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 10:51:32 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	t_node	*current_node;

	if (is_stack_empty(stack))
		return (1);
	current_node = stack->top;
	while (current_node->next)
	{
		if (current_node->data > current_node->next->data)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}
