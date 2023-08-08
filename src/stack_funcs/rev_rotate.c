/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:29 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 13:02:25 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*new_top;
	t_node	*current_node;

	if (is_stack_empty(stack) || stack->top->next == NULL)
		return ;
	current_node = stack->top;
	while (current_node->next->next)
		current_node = current_node->next;
	new_top = current_node->next;
	current_node->next = NULL;
	stack->bottom = current_node;
	new_top->next = stack->top;
	stack->top = new_top;
	if (stack->top == stack->max)
		stack->max_pos = 1;
	else if (stack->bottom == stack->max)
		stack->max_pos = stack->size;
	else
		stack->max_pos++;
}

void	rra(t_stack *a)
{
	reverse_rotate_stack(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate_stack(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_printf("rrr\n");
}
