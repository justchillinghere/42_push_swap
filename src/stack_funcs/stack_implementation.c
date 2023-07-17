/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:04:31 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/17 19:47:40 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *create_node(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = num;
	node->next = NULL;
	return (node);
}

t_stack *create_stack()
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	return (new_stack);
}

int	is_stack_empty(t_stack *stack)
{
	if (!stack->top)
		return (1);
	return (0);
}

void	push_stack(t_stack *stack, int num)
{
	t_node	*new_node;

	new_node = create_node(num);
	new_node->next = stack->top;
	stack->top = new_node;
	if (stack->top->next == NULL) // if there's only one element, top and bottom point to the same element
		stack->bottom = new_node;
}

void	print_stack(t_stack *stack)
{
	t_node *current_node;

	current_node = stack->top;
	while (current_node)
	{
		ft_printf("|%d|\n", current_node->data);
		current_node = current_node->next;
	}
}

int pop_stack(t_stack *stack)
{
	t_node *pointer;
	int	deleted_val;

	if (is_stack_empty(stack))
		return (-1);
	pointer = stack->top;
	deleted_val = pointer->data;
	stack->top = stack->top->next;
	free(pointer);
	return (deleted_val);
}

void	free_stack(t_stack *stack)
{
	while (!is_stack_empty(stack))
		pop_stack(stack);
}

int	get_stack_size(t_stack *stack)
{
	t_node	*node;
	int	i;

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
