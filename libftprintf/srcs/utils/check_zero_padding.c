/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero_padding.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:41:12 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/17 15:41:07 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_zero_padding_flag(t_params *pf)
{
	if ((pf->justify_left) || (pf->use_precision))
		pf->zeroes_padding = 0;
	else if (pf->zeroes_padding)
	{
		pf->precision = pf->width;
		pf->width = 0;
		if ((pf->is_negative) || (pf->space_if_no_sign) || (pf->print_sign))
			pf->precision--;
	}
}
