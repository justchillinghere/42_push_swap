/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_impl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:41:22 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/07 17:45:25 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void test_stack_impl()
{
    // Test create_node function
    t_node *node = create_node(5);
    printf("Node data: %d\n", node->data);
    printf("Node next: %p\n", node->next);

    // Test create_stack function
    t_stack *stack = create_stack();
    printf("Stack top: %p\n", stack->top);

    // Test push_stack function
    push_stack(stack, 10);
    push_stack(stack, 20);
    push_stack(stack, 30);
    printf("Stack after pushing: \n");
    print_stack(stack);

    // Test pop_stack function
    int popped_val = pop_stack(stack);
    printf("Popped value: %d\n", popped_val);
    printf("Stack after popping: \n");
    print_stack(stack);

    // Test free_stack function
    free_stack(stack);
    printf("Stack after freeing: \n");
    print_stack(stack);
}

