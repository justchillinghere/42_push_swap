/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:30:29 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 15:35:01 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_specifier(t_params *pf, t_va_list_wrapper *ap)
{
	char	specifier;

	specifier = *(pf->format);
	if (specifier == 'i' || specifier == 'd')
		return (print_int(pf, ap));
	if (specifier == 's')
		return (print_str(pf, ap));
	if (specifier == 'u')
		return (print_int(pf, ap));
	if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		return (print_hex(pf, ap));
	if (specifier == 'c' || specifier == '%')
		return (print_char(pf, ap));
	return (0);
}
