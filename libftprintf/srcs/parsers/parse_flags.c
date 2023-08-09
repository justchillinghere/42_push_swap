/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:16:49 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 15:33:46 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flags(t_params *pf, t_va_list_wrapper *ap)
{
	char	flag;

	flag = *(pf->format);
	if (flag == '-')
		pf->justify_left = 1;
	else if (flag == '+')
		pf->print_sign = 1;
	else if (flag == ' ')
		pf->space_if_no_sign = 1;
	else if (flag == '#')
		pf->hashtag = 1;
	else if (flag == '0')
		pf->zeroes_padding = 1;
	pf->format++;
	return (parse_format(pf, ap));
}
