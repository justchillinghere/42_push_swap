/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:46:12 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/17 15:58:49 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_HEX_H
# define PRINTF_HEX_H

# include "ft_printf.h"

void	print_width_hex(t_params *pf, int hex_len);
void	print_precision_hex(t_params *pf, int hex_len);
void	print_prefix(t_params *pf);

#endif