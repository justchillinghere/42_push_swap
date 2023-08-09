/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:28:53 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 15:34:13 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(t_params *pf, t_va_list_wrapper *ap)
{
	char	*format_str;

	format_str = pf->format;
	if (ft_strchr("-+ #0", *format_str))
		return (parse_flags(pf, ap));
	else if (ft_strchr("9876543210*", *format_str))
		return (parse_width(pf, ap));
	else if (ft_strchr(".", *format_str))
		return (parse_precision(pf, ap));
	else if (ft_strchr("cspdiuxX%", *format_str))
		return (parse_specifier(pf, ap));
	return (0);
}
