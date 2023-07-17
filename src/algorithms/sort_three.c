/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:08:41 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/17 20:33:53 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort three elements stack (Max 2 moves)
void	sort_three(t_stack *stack)
{
	int	max_stack_value;
	
	max_stack_value = find_max_stack_value(stack);
	if (stack->top->data == max_stack_value)
		ra(stack);
	else if (max_stack_value == stack->top->next->data)
		rra(stack);
	if (stack->top->data > stack->top->next->data)
		sa(stack);
}
