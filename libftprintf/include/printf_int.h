/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:07:39 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/15 15:34:55 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_INT_H
# define PRINTF_INT_H

# include "ft_printf.h"

void	print_width_num(t_params *pf, int num_len);
void	print_precision_num(t_params *pf, int num_len);
void	print_sign(t_params *pf);

#endif