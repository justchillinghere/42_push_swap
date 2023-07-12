/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:09:57 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/12 15:24:46 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack_node 
{
	int data;
	struct s_stack_node *next;
} 	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
}	t_stack;

t_stack *create_stack();
t_node *create_node(int num);
void	free_stack(t_stack *stack);
int 	pop_stack(t_stack *stack);
void	print_stack(t_stack *stack);
void	push_stack(t_stack *stack, int num);
int		is_stack_empty(t_stack *stack);

int		count_argc(char **argv);
int		get_stack_size(t_stack *stack);

void	rotate_stack(t_stack *stack);
void 	rr(t_stack *a, t_stack *b);
void 	ra(t_stack *a);
void 	rb(t_stack *b);

void	swap_stack(t_stack *stack);
void 	sa(t_stack *a);
void 	sb(t_stack *b);
void 	ss(t_stack *a, t_stack *b);

void	push_from_stack_to_stack(t_stack *from, t_stack *to);
void 	pa(t_stack *a, t_stack *b);
void 	pb(t_stack *a, t_stack *b);

void	reverse_rotate_stack(t_stack *stack);
void 	rra(t_stack *a);
void 	rrb(t_stack *b);
void 	rrr(t_stack *a, t_stack *b);

#endif