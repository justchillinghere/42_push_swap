/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:50:40 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/31 17:44:09 by luchitel         ###   ########.fr       */
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

	if(stack->top == stack->max)
		stack->max_pos = 1;
	else if (stack->top->next == stack->max)
		stack->max_pos = 2;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap_stack(b);
	ft_printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	ft_printf("ss\n");
}
