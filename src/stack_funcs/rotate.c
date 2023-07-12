/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:10:20 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/12 14:49:43 by luchitel         ###   ########.fr       */
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

void ra(t_stack *a)
{
	rotate_stack(a);
	printf("ra\n");
}

void rb(t_stack *b)
{
	rotate_stack(b);
	printf("rb\n");
}

void rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	printf("rr\n");
}
