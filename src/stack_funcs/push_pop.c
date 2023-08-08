/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:43:41 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 11:01:26 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *stack, int num)
{
	t_node	*new_node;

	new_node = create_node(num);
	new_node->next = stack->top;
	stack->top = new_node;
	if (stack->top->next == NULL)
	{
		stack->bottom = new_node;
		stack->max = stack->top;
		stack->min = stack->top;
		stack->max_pos = 1;
	}
	else
		check_pushed_val(stack);
	stack->size++;
	if (stack->max == stack->top)
		stack->max_pos = 1;
	else
		stack->max_pos++;
}

int	pop_stack(t_stack *stack)
{
	t_node	*pointer;
	int		deleted_val;

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
