/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:08:41 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/21 23:03:50 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort three elements stack (Max 2 moves)
void	sort_three(t_stack *stack)
{
	if (stack->top->data == stack->max->data)
		ra(stack);
	else if (stack->max->data == stack->top->next->data)
		rra(stack);
	if (stack->top->data > stack->top->next->data)
		sa(stack);
}
