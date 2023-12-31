/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:10:20 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 13:00:43 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack)
{
	t_node	*new_bottom;

	if (is_stack_empty(stack) || stack->top->next == NULL)
		return ;
	new_bottom = stack->top;
	stack->top = stack->top->next;
	stack->bottom->next = new_bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->next = NULL;
	if (stack->top == stack->max)
		stack->max_pos = 1;
	else if (stack->bottom == stack->max)
		stack->max_pos = stack->size;
	else
		stack->max_pos--;
}

void	ra(t_stack *a)
{
	rotate_stack(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rr\n");
}
