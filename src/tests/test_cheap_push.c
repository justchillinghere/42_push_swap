/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cheap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:19:20 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/28 16:29:03 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

static t_stack *stack_a;
static t_stack *stack_b;

static void	setup_stack(void)
{
	stack_a = create_stack();
	stack_b = create_stack();
	push_stack(stack_a, 8);
	push_stack(stack_a, 4);
	push_stack(stack_a, 9);
	push_stack(stack_a, 3);
	push_stack(stack_a, 6);
	push_stack(stack_a, 1);
	push_stack(stack_a, 7);
	push_stack(stack_a, 2);
	push_stack(stack_a, 5);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
}

static void	teardown_stack(void)
{
	free_stack(stack_a);
	free_stack(stack_b);
	ft_printf("Freed\n");
}

void	print_steps(t_score *score)
{
	int	i = 0;

	while (i < 6)
	{
		ft_printf("Score action ind #%d is %d\n", i, score->actions[i]);
		i++;
	}
	ft_printf("Total actions: %d\n", score->total_score);
}

TestSuite(cheap_algo, .init=setup_stack, .fini=teardown_stack);

Test(cheap_algo, test_score_set)
{
	t_score	*min_score;

	min_score = malloc(sizeof(t_score));
	set_null_score(min_score);
	free(min_score);
}

Test(cheap_algo, test_cheap)
{

	// find_cheapest(stack_a, stack_b, min_score);
	sort_big(stack_a);
}