/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:24:17 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/17 15:34:38 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calculate_width(t_params *pf, int hex_len)
{
	int	calc_width;

	if (pf->precision > hex_len)
		calc_width = pf->width - pf->precision;
	else
		calc_width = pf->width - hex_len;
	if (pf->hashtag || *pf->format == 'p')
		calc_width -= 2;
	return (calc_width);
}

void	print_width_hex(t_params *pf, int hex_len)
{
	int		calc_width;
	char	char_to_print;

	calc_width = calculate_width(pf, hex_len);
	if (calc_width <= 0)
		return ;
	char_to_print = ' ';
	if (pf->zeroes_padding)
		char_to_print = '0';
	while (calc_width-- > 0)
		pf->total_length += write(1, &char_to_print, 1);
}

void	print_precision_hex(t_params *pf, int hex_len)
{
	int	calc_precision;

	calc_precision = pf->precision - hex_len;
	if (calc_precision <= 0)
		return ;
	while (calc_precision--)
		pf->total_length += write(1, "0", 1);
}

void	print_prefix(t_params *pf)
{
	pf->hashtag = 0;
	pf->total_length += 2;
	if (*pf->format == 'x' || *pf->format == 'p')
		ft_putstr("0x");
	else
		ft_putstr("0X");
}
