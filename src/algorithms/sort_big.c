/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:58:00 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/28 16:30:13 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_cheapest(t_stack *stack_a, t_stack *stack_b, t_score *score);
static void	do_action(t_stack *stack_a, t_stack *stack_b, int action_index);

void	sort_big(t_stack *stack_a)
{
	t_score	*min_score;
	t_stack	*stack_b;

	stack_b = create_stack();
	min_score = malloc(sizeof(t_score));
	set_null_score(min_score);
	// ft_printf("Stack A before:\n");
	// print_stack(stack_a);
	// ft_printf("\n--------\n");
	pb(stack_a, stack_b); // Push two first arbitrary elements to stack_b
	pb(stack_a, stack_b);

	while (stack_a->size > 3)
	{
		find_cheapest(stack_a, stack_b, min_score);
		move_cheapest(stack_a, stack_b, min_score); // moves the cheapest element to the top
		pb(stack_a, stack_b);
		set_null_score(min_score);
	}
	ft_printf("Stack A after:\n");
	print_stack(stack_a);
	ft_printf("\n--------\n");
	ft_printf("Stack B:\n");
	print_stack(stack_b);
	ft_printf("\n--------\n");

	free_stack(stack_b);
	free(min_score);
}

static void	move_cheapest(t_stack *stack_a, t_stack *stack_b, t_score *score)
{
	int i;
	
	i = 5;
	while (i >= 0)
	{
		while (score->actions[i] != 0)
		{
			do_action(stack_a, stack_b, i);
			score->actions[i]--;
		}
		i--;
	}
}

static void	do_action(t_stack *stack_a, t_stack *stack_b, int action_index)
{
	if (action_index == ra_count)
		ra(stack_a);
	else if (action_index == rb_count)
		rb(stack_b);
	else if (action_index == rr_count)
		rr(stack_a, stack_b);
	else if (action_index == rra_count)
		rra(stack_a);
	else if (action_index == rrb_count)
		rrb(stack_b);
	else
		rrr(stack_a, stack_b);
}
