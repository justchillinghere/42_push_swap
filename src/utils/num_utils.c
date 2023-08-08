/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:16:15 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/07 19:10:51 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int value)
{
	if (value < 0)
		return (-1 * value);
	else
		return (value);
}

int	min(int a, int b)
{
	if (a == b)
		return (a);
	else if (a < b)
		return (a);
	else
		return (b);
}
