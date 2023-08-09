/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:17:10 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 15:35:49 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width(t_params *pf, char padding)
{
	while (pf->width > 1)
	{
		--pf->width;
		++pf->total_length;
		write(1, &padding, 1);
	}
}

static void	put_char(t_params *pf, t_va_list_wrapper *ap)
{
	char	char_to_print;

	if (*pf->format == '%')
		char_to_print = '%';
	else
		char_to_print = (char) va_arg(ap->v, int);
	pf->total_length += write(1, &char_to_print, 1);
}

int	print_char(t_params *pf, t_va_list_wrapper *ap)
{
	char	padding;

	padding = ' ';
	if (pf->zeroes_padding && !(pf->justify_left))
		padding = '0';
	if (!(pf->justify_left))
		print_width(pf, padding);
	put_char(pf, ap);
	if (pf->justify_left)
		print_width(pf, padding);
	return (pf->total_length);
}
