/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:02:43 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/17 15:47:12 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_params(t_params *params, char *format_str)
{
	params->width = 0;
	params->precision = 0;
	params->justify_left = 0;
	params->print_sign = 0;
	params->space_if_no_sign = 0;
	params->zeroes_padding = 0;
	params->is_zero = 0;
	params->hashtag = 0;
	params->is_percent = 0;
	params->total_length = 0;
	params->is_negative = 0;
	params->arg_value_len = 0;
	params->use_precision = 0;
	params->format = format_str;
}
