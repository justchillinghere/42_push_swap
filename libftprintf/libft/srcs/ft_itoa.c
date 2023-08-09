/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:18:21 by luchitel          #+#    #+#             */
/*   Updated: 2023/03/11 18:05:49 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_size(int n)
{
	int	size;

	size = 0;
	if (n < 0 || n == 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

void	putchar_rev(char *dest, int nbr)
{
	if (nbr < 10)
		*dest = nbr + '0';
	else
	{
		*dest = nbr % 10 + '0';
		putchar_rev(dest - 1, nbr / 10);
	}
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		size;

	size = ft_find_size(nbr);
	result = (char *)malloc(sizeof(char) * size + 1);
	if (!result)
		return (NULL);
	if (nbr == -2147483648)
		return (ft_memcpy(result, "-2147483648", size + 1));
	else if (nbr < 0)
	{
		*result = '-';
		nbr = -nbr;
	}
	putchar_rev(result + size - 1, nbr);
	result[size] = '\0';
	return (result);
}
