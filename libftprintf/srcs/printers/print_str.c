/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:27:57 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 15:37:25 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str_with_precision(t_params *pf, t_va_list_wrapper *ap)
{
	char	*str;

	str = va_arg(ap->v, char *);
	if (str)
	{
		if (pf->use_precision)
			str = ft_substr(str, 0, pf->precision);
		else
			str = ft_strdup(str);
	}
	else
	{
		free(str);
		if (!pf->use_precision)
			pf->precision = 6;
		str = ft_substr("(null)", 0, pf->precision);
		if (str == NULL)
			return (0);
	}
	return (str);
}

void	print_str_width(t_params *pf, int str_len)
{
	char	c;

	c = ' ';
	if (pf->zeroes_padding)
		c = '0';
	if (pf->width <= str_len)
		return ;
	while (pf->width > str_len)
	{
		pf->total_length += write(1, &c, 1);
		pf->width--;
	}
}

int	print_str(t_params *pf, t_va_list_wrapper *ap)
{
	char	*str;
	int		str_len;

	str = get_str_with_precision(pf, ap);
	str_len = ft_strlen(str);
	if (!pf->justify_left)
		print_str_width(pf, str_len);
	ft_putstr(str);
	free(str);
	pf->total_length += str_len;
	if (pf->justify_left)
		print_str_width(pf, str_len);
	return (pf->total_length);
}
