/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:10:52 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/17 15:46:39 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits_base(unsigned long long int num, int base)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		count++;
		num /= base;
	}
	return (count);
}

static char	*covert_unsigned_to_base(unsigned long long int num, \
									char *char_set, int base)
{
	char	*res_str;
	int		num_len;

	if (num == 0)
		return (ft_strdup("0"));
	num_len = count_digits_base(num, base);
	res_str = (char *) malloc(sizeof(char) * (num_len + 1));
	if (!res_str)
		return (0);
	res_str[num_len] = '\0';
	while (num > 0)
	{
		res_str[--num_len] = char_set[num % base];
		num = num / base;
	}
	return (res_str);
}

char	*convert_arg_to_custom_base(unsigned long long int num, \
									char *char_set, int base, t_params *pf)
{
	if (pf->use_precision && pf->precision == 0 && num == 0)
		return (ft_strdup(""));
	else
		return (covert_unsigned_to_base(num, char_set, base));
}
