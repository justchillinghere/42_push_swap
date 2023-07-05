/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:02:05 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/05 18:58:43 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	// t_node	*node_a;
	// t_node	*node_b;

	// node_a = NULL;
	// node_b = NULL;
	if (argc == 1 || !argv[1][0])
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv++;
	ft_printf("Hello_world");
	// init_stack(node_a, argv);
	// stack_free(node_a);
	// stack_free(node_b);
	return (0);
}