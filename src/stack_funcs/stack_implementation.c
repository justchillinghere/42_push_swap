/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:04:31 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/01 18:57:28 by luchitel         ###   ########.fr       */
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
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	new_stack->max = NULL;
	new_stack->min = NULL;
	new_stack->size = 0;
	new_stack->max_pos = 0;
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
	{
		stack->bottom = new_node;
		stack->max = stack->top;
		stack->min = stack->top;
		stack->max_pos = 1;
	}
	else
		check_pushed_val(stack); // If there're 2 or more elements, check for new min and max
	
	stack->size++;
	if (stack->max == stack->top)
		stack->max_pos = 1;
	else
		stack->max_pos++;
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
	check_popped_val(stack, deleted_val);
	free(pointer);
	stack->size--;
	if (stack->max == stack->top)
		stack->max_pos = 1;
	else
		stack->max_pos--;
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
