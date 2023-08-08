/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:32:38 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 16:39:02 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_data_error_in_value(int *arr,
				char *value_str,
				char **argv,
				int argc)
{
	free(arr);
	free(value_str);
	free_heap_argv(argv, argc);
	ft_error();
}

void	ft_error(void)
{	
	ft_putendl_fd("Error", 2);
	exit(1);
}
