/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:11:41 by hipham            #+#    #+#             */
/*   Updated: 2023/11/08 21:15:16 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int num, int *c_count)
{
	if (num >= 10)
		ft_putunbr(num / 10, c_count);
	if (*c_count != -1)
		ft_putchr(num % 10 + '0', c_count);
	return (*c_count);
}
