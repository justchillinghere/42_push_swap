/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:25:53 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 15:36:30 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printf_hex.h"

char	*get_hex_from_arg(t_params *pf, t_va_list_wrapper *ap)
{
	char	*num_str;

	if (*pf->format == 'p')
		num_str = convert_arg_to_custom_base(
				(unsigned long long int) va_arg(ap->v, void *),
				"0123456789abcdef", 16, pf);
	else if (*pf->format == 'x')
		num_str = convert_arg_to_custom_base(va_arg(ap->v, unsigned int),
				"0123456789abcdef", 16, pf);
	else
		num_str = convert_arg_to_custom_base(va_arg(ap->v, unsigned int),
				"0123456789ABCDEF", 16, pf);
	return (num_str);
}

int	print_hex(t_params *pf, t_va_list_wrapper *ap)
{
	char	*hex_str;
	int		hex_len;

	hex_str = get_hex_from_arg(pf, ap);
	hex_len = ft_strlen(hex_str);
	check_zero_padding_flag(pf);
	if (!(pf->justify_left) && !(pf->zeroes_padding))
		print_width_hex(pf, hex_len);
	if (hex_len > 0)
	{
		if (*pf->format == 'p' || (*hex_str != '0' && pf->hashtag))
			print_prefix(pf);
		print_precision_hex(pf, hex_len);
		ft_putstr(hex_str);
		pf->total_length += hex_len;
	}
	free(hex_str);
	if ((pf->justify_left))
		print_width_hex(pf, hex_len);
	return (pf->total_length);
}
