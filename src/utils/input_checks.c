/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:43:23 by luchitel          #+#    #+#             */
/*   Updated: 2023/07/07 15:38:30 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_argc(char **argv)
{
	int	 i;

	i = 0;
	while(argv[i])
		i++;
	return (i);
}

int	unify_args(int argc, char **argv)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' '); // convert "1 2 3" to "1", "2", "3"
		argc = count_argc(argv);
	}
	else // if argv is already "1" "2" "3" 
	{
		argv++;
		argc--;
	}
	return (argc);
}