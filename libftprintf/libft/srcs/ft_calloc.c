/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:42:53 by luchitel          #+#    #+#             */
/*   Updated: 2023/03/12 14:08:49 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_overflow(size_t res, size_t count, size_t size)
{
	if (count == 0 || size == 0)
		return (0);
	else if (count == res / size)
		return (0);
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*loc;
	size_t	res;

	res = count * size;
	if (is_overflow(res, count, size))
		return (NULL);
	loc = (void *) malloc(res);
	if (!loc)
		return (0);
	ft_bzero(loc, res);
	return (loc);
}
