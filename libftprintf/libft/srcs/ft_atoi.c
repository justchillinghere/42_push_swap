/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:18:19 by luchitel          #+#    #+#             */
/*   Updated: 2023/03/06 13:28:28 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *orig_str)
{
	int		result;
	int		sign;
	char	*str;

	result = 0;
	sign = 1;
	str = (char *) orig_str;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((*str > 47 && *str < 58) && *str)
	{
		result = result * 10 + sign * (*str - 48);
		str++;
	}
	return (result);
}
