/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:35:44 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/17 20:34:02 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_stack_value(t_stack *stack)
{
	int	max_value;
	t_node	*tmp_node;

	max_value = 0;
	tmp_node = stack->top;
	while (tmp_node)
	{
		if (tmp_node->data > max_value)
			max_value = tmp_node->data;
		tmp_node = tmp_node->next;
	}
	return (max_value);
}
