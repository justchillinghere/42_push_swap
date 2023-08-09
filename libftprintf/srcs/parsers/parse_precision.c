/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:15:43 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 15:34:48 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_precision(t_params *pf, t_va_list_wrapper *ap)
{
	char	prec_specifier;

	prec_specifier = *(++pf->format);
	pf->use_precision = 1;
	if (prec_specifier == '*')
	{
		pf->precision = va_arg(ap->v, int);
		pf->format++;
		if (pf->precision < 0)
			pf->use_precision = 0;
	}
	else
	{
		while (ft_isdigit(prec_specifier) && prec_specifier)
		{
				pf->precision = pf->precision * 10 + (prec_specifier - '0');
				prec_specifier = *(++(pf->format));
		}
	}
	return (parse_format(pf, ap));
}
