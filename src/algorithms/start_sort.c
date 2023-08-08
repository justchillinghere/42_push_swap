/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:10:19 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/07 18:49:01 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_stack *stack_a)
{
	if (stack_a->size < 3)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else
		sort_big(stack_a);
}
