/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:43:41 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/21 23:02:26 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_stack_to_stack(t_stack *from, t_stack *to)
{
	t_node	*tmp_node;

	if(is_stack_empty(from))
		return;
	tmp_node = from->top;
	tmp_node->next = to->top;
	from->top = from->top->next;
	to->top = tmp_node;

	check_popped_val(from, tmp_node->data); // Check if popped value was min or max and find new ones
	check_pushed_val(to); // Check if new top value is min or max and if so, set new ones
}

void pa(t_stack *a, t_stack *b)
{
	push_from_stack_to_stack(b, a);
	ft_printf("pa\n");
}

void pb(t_stack *a, t_stack *b)
{
	push_from_stack_to_stack(a, b);
	ft_printf("pb\n");
}
