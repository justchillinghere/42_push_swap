/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:37:56 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 17:27:30 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_heap_argv(char **argv, int argc)
{
	int	i;

	i = 0;
	while (i <= argc)
		free(argv[i++]);
	free(argv);
}
