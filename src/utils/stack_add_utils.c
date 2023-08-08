/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:42:25 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 11:04:54 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	t_node	*current_node;

	if (is_stack_empty(stack))
		return (1);
	current_node = stack->top;
	while (current_node->next)
	{
		if (current_node->data > current_node->next->data)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	t_node	*current_node;

	current_node = stack->top;
	while (current_node)
	{
		ft_printf("|%d|\n", current_node->data);
		current_node = current_node->next;
	}
}

int	get_stack_size(t_stack *stack)
{
	t_node	*node;
	int		i;

	node = stack->top;
	i = 1;
	if (is_stack_empty(stack))
		return (0);
	while (node->next)
	{
		node = node->next;
		i++;
	}
	return (i);
}
