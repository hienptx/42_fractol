/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:19:09 by hipham            #+#    #+#             */
/*   Updated: 2023/11/08 21:14:15 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num, int *c_count)
{
	long	nbr;

	nbr = (long)num;
	if (nbr < 0)
	{
		if (write(1, "-", 1) == -1)
			return ((*c_count) = -1);
		(*c_count)++;
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10, c_count);
	if (*c_count != -1)
		ft_putchr(nbr % 10 + '0', c_count);
	return (*c_count);
}
