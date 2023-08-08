/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:09:57 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 16:40:15 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"
# include "limits.h"
# include <unistd.h>

enum					e_options_names
{
	ra_count,
	rb_count,
	rr_count,
	rra_count,
	rrb_count,
	rrr_count
};
enum					e_action_options
{
	rr_option,
	rrr_option,
	ra_rrb_option,
	rra_rb_option
};

# define ERROR 0
# define OK 1

typedef struct s_stack_node
{
	int					data;
	struct s_stack_node	*next;
}						t_node;

typedef struct s_stack
{
	t_node				*top;
	t_node				*bottom;
	int					size;
	t_node				*min;
	t_node				*max;
	int					max_pos;
}						t_stack;

typedef struct s_element_score
{
	int					actions[6];
	int					total_score;
}						t_score;

// Stack implementation
t_stack					*create_stack(void);
t_node					*create_node(int num);
void					free_stack(t_stack *stack);
int						pop_stack(t_stack *stack);
void					print_stack(t_stack *stack);
void					push_stack(t_stack *stack, int num);
int						is_stack_empty(t_stack *stack);

//Input checking
char					**get_correct_input_str(int *argc, char **argv);
int						is_format_correct(int argc, char **argv);
int						*get_unique_values_array(int argc, char **argv);
int						arr_has_value(int *arr, int size, int value);
t_stack					*form_init_stack(int *arr, int argc);
t_stack					*get_stack_from_input(int *argc, char **argv);

// Utils
int						count_argc(char **argv);
int						get_stack_size(t_stack *stack);
int						is_stack_sorted(t_stack *stack);
t_node					*get_max_stack_value(t_stack *stack);
t_node					*get_min_stack_value(t_stack *stack);
void					check_popped_val(t_stack *new_stack, int popped_val);
void					check_pushed_val(t_stack *stack);
int						abs(int value);
int						min(int a, int b);
void					copy_score(t_score *from, t_score *to);
void					set_null_score(t_score *score);
void					ft_error(void);
void					print_score(t_score *score);
void					free_data_error_in_value(int *arr,
							char *value_str,
							char **argv,
							int argc);
void					free_heap_argv(char **argv, int argc);

// Rules
void					rotate_stack(t_stack *stack);
void					rr(t_stack *a, t_stack *b);
void					ra(t_stack *a);
void					rb(t_stack *b);

void					swap_stack(t_stack *stack);
void					sa(t_stack *a);
void					sb(t_stack *b);
void					ss(t_stack *a, t_stack *b);

void					push_from_stack_to_stack(t_stack *from, t_stack *to);
void					pa(t_stack *a, t_stack *b);
void					pb(t_stack *a, t_stack *b);

void					reverse_rotate_stack(t_stack *stack);
void					rra(t_stack *a);
void					rrb(t_stack *b);
void					rrr(t_stack *a, t_stack *b);

// Sorting algorithms
void					start_sort(t_stack *stack_a);
void					sort_three(t_stack *stack);
void					sort_big(t_stack *stack_a);
void					move_cheapest(t_stack *stack_a, t_stack *stack_b,
							t_score *score);
// Sort b from a utils
void					sort_b_from_a(t_stack *stack_a,
							t_stack *stack_b, t_score *min_score);
void					find_cheapest(t_stack *stack_a, t_stack *stack_b,
							t_score *min_score);
void					count_place_in_b(int push_value, t_stack *stack_b,
							t_score *current_score);
int						find_min_option_index(int options[4]);
void					tranform_one_dir_rotate(t_score *score,
							int option_num);
void					transform_two_dir_rotate(t_score *score,
							int option_num);
void					count_min_steps(t_score *score);

// Utils for sorting a from b
void					sort_a_from_b(t_stack *stack_a,
							t_stack *stack_b, t_score *min_score);
void					count_min_to_top(t_score *score, t_stack *stack);
void					transform_rotations_ba(t_score *score);
int						find_stack_min_pos(t_stack *stack);
void					count_place_in_stack(int push_value, t_stack *stack,
							t_score *current_score);

#endif
