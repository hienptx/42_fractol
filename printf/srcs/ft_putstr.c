/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:06:39 by hipham            #+#    #+#             */
/*   Updated: 2023/11/08 21:09:12 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int *c_count)
{
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return ((*c_count) = -1);
		*c_count = *c_count + 6;
	}
	else
	{
		while (*s != '\0' && *c_count != -1)
		{
			ft_putchr(*s, c_count);
			s++;
		}
	}
	return (*c_count);
}
