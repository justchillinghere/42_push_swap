/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:59:43 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 15:35:16 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_width(t_params *pf, t_va_list_wrapper *ap)
{
	char	width_specifier;

	width_specifier = *(pf->format);
	if (width_specifier == '*')
	{
		pf->width = va_arg(ap->v, int);
		pf->format++;
	}
	else
	{
		while (ft_isdigit(width_specifier) && width_specifier)
		{
				pf->width = pf->width * 10 + (width_specifier - '0');
				width_specifier = *(++(pf->format));
		}
	}
	if (pf->width < 0)
	{
		pf->width *= -1;
		pf->justify_left = 1;
	}
	return (parse_format(pf, ap));
}
