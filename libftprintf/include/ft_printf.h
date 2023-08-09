/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:59 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/20 15:31:59 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_params {
	int		width;
	int		precision;
	int		justify_left;
	int		print_sign;
	int		space_if_no_sign;
	int		hashtag;
	int		zeroes_padding;
	int		is_zero;
	int		is_percent;
	int		arg_value_len;
	int		total_length;
	int		is_negative;
	int		use_precision;
	char	*format;
}	t_params;

typedef struct va_list_wrapper {
	va_list	v;
}	t_va_list_wrapper;

int		ft_printf(const char *str, ...);
int		print_init(char *str, t_va_list_wrapper ap, int length);
int		ft_init_parse(char **str, t_va_list_wrapper *ap);
int		parse_format(t_params *pf, t_va_list_wrapper *ap);
int		parse_flags(t_params *pf, t_va_list_wrapper *ap);
int		parse_specifier(t_params *pf, t_va_list_wrapper *ap);
int		parse_precision(t_params *pf, t_va_list_wrapper *ap);
int		parse_width(t_params *pf, t_va_list_wrapper *ap);
int		print_str(t_params *pf, t_va_list_wrapper *ap);
int		print_hex(t_params *pf, t_va_list_wrapper *ap);
int		print_char(t_params *pf, t_va_list_wrapper *ap);
int		print_int(t_params *pf, t_va_list_wrapper *ap);
void	initialize_params(t_params *params, char *format_str);
void	check_zero_padding_flag(t_params *pf);
char	*convert_arg_to_custom_base(unsigned long long int num, \
									char *char_set, int base, t_params *pf);
#endif
