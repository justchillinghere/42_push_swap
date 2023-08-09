/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:35:46 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/17 15:35:20 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calculate_width(t_params *pf, int num_len)
{
	int	calc_width;

	calc_width = 0;
	if (pf->precision > num_len)
		calc_width = pf->width - pf->precision;
	else
	{
		calc_width = pf->width - num_len;
	}
	if (pf->is_negative || pf->print_sign || pf->space_if_no_sign)
		calc_width--;
	return (calc_width);
}

void	print_width_num(t_params *pf, int num_len)
{
	int		calc_width;
	char	char_to_print;

	calc_width = calculate_width(pf, num_len);
	if (calc_width <= 0)
		return ;
	char_to_print = ' ';
	if (pf->zeroes_padding)
		char_to_print = '0';
	while (calc_width--)
		pf->total_length += write(1, &char_to_print, 1);
}

void	print_precision_num(t_params *pf, int num_len)
{
	int	calc_precision;

	calc_precision = pf->precision - num_len;
	if (calc_precision <= 0)
		return ;
	while (calc_precision--)
		pf->total_length += write(1, "0", 1);
}

void	print_sign(t_params *pf)
{
	char	sign_to_print;

	sign_to_print = '\0';
	if (pf->is_negative)
		sign_to_print = '-';
	else if (pf->print_sign)
		sign_to_print = '+';
	else if (pf->space_if_no_sign)
		sign_to_print = ' ';
	if (!sign_to_print)
		return ;
	write(1, &sign_to_print, 1);
	pf->total_length += 1;
}
