/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:43:41 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/07 19:07:03 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_stack_to_stack(t_stack *from, t_stack *to)
{
	int		pop_val;

	if (is_stack_empty(from))
		return ;
	pop_val = pop_stack(from);
	push_stack(to, pop_val);
}

void	pa(t_stack *a, t_stack *b)
{
	push_from_stack_to_stack(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push_from_stack_to_stack(a, b);
	ft_printf("pb\n");
}
