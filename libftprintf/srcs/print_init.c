/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:02:07 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 16:20:02 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_init(char *str, t_va_list_wrapper ap, int length)
{
	char	*pointer_to_percent;

	pointer_to_percent = ft_strchr(str, '%');
	if (!pointer_to_percent)
	{
		length += ft_strlen(str);
		ft_putstr(str);
		return (length);
	}
	length += write(1, str, pointer_to_percent - str);
	length += ft_init_parse(&pointer_to_percent, &ap);
	return (print_init(pointer_to_percent, ap, length));
}
