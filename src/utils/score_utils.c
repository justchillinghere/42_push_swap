/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:22:41 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/08 10:48:43 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_null_score(t_score *score)
{
	int	i;

	i = 0;
	while (i < 6)
		score->actions[i++] = 0;
	score->total_score = 0;
}

void	copy_score(t_score *from, t_score *to)
{
	int	i;

	i = -1;
	while (++i < 6)
		to->actions[i] = from->actions[i];
	to->total_score = from->total_score;
}
