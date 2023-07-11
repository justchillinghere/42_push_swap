/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:50:40 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/07 17:39:58 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	// Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
	t_node	*first;
	t_node	*second;

	first = stack->top;
	second = stack->top->next;
	if(!(stack->top) || !(stack->top->next))
		return;
	first->next = second->next;
	second->next = stack->top;
	stack->top = second;
}