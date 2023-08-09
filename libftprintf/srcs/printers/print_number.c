/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:30:44 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 15:36:52 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printf_int.h"

static void	print_number(t_params *pf, char *number_str)
{
	int	num_len;

	num_len = ft_strlen(number_str);
	check_zero_padding_flag(pf);
	if (!(pf->justify_left) && !(pf->zeroes_padding))
		print_width_num(pf, num_len);
	if (num_len > 0)
	{
		print_sign(pf);
		print_precision_num(pf, num_len);
		ft_putstr(number_str);
		pf->total_length += num_len;
	}
	if (pf->justify_left)
		print_width_num(pf, num_len);
}

int	print_int(t_params *pf, t_va_list_wrapper *ap)
{
	long int	number;
	char		*number_str;

	if (*pf->format == 'd' || *pf->format == 'i')
	{
		number = va_arg(ap->v, int);
		if (number < 0)
		{
			pf->is_negative = 1;
			number = (unsigned int) -number;
		}
	}
	else
		number = va_arg(ap->v, unsigned int);
	number_str = convert_arg_to_custom_base(number, "0123456789", 10, pf);
	print_number(pf, number_str);
	free(number_str);
	return (pf->total_length);
}
