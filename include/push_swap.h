/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:09:57 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/11 18:49:37 by luchitel         ###   ########.fr       */
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
int	is_stack_empty(t_stack *stack);

int		count_argc(char **argv);
void	swap_stack(t_stack *stack);
int		get_stack_size(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

#endif