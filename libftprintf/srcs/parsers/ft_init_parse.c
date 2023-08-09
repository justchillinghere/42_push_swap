/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:25:39 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 15:38:02 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	find_format_length(char *str)
{
	unsigned int	i;

	i = 0;
	while (!ft_strchr("cspdiuxX%", str[i]) && str[i])
		i++;
	return (i);
}

// Init parse takes pointer to the % char, finds format parameters,
// parses it into structure and starts printing mechanism.
// It changes str inplace to the position of the specifier
// and returns number of characters that has been printed.

int	ft_init_parse(char **str, t_va_list_wrapper *ap)
{
	t_params		*pf;
	char			*params_str;
	int				result;
	unsigned int	format_len;

	*str += 1;
	pf = (t_params *) malloc(sizeof(t_params));
	format_len = find_format_length(*str);
	params_str = ft_substr(*str, 0, (size_t) format_len + 1);
	*str += format_len + 1;
	if (!pf || !params_str)
		return (-1);
	initialize_params(pf, params_str);
	result = parse_format(pf, ap);
	free(params_str);
	free(pf);
	return (result);
}
