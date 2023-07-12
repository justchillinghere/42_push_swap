/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:43:41 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/12 14:17:23 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_stack_to_stack(t_stack *from, t_stack *to)
{
	t_node	tmp_node;

	if(is_stack_empty(from))
		return;
	tmp_node = from->top;
	tmp_node->next = to->top;
	to->top = tmp_node;

	from->top = from->top->next;
}

void pa(t_stack *a, t_stack *b)
{
	push_from_stack_to_stack(b, a);
	printf("pa\n");
}

void pb(t_stack *a, t_stack *b)
{
	push_from_stack_to_stack(a, b);
	printf("pb\n");
}
