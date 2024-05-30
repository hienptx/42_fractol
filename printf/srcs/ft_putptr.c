/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:35:04 by hipham            #+#    #+#             */
/*   Updated: 2023/11/08 21:12:12 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	get_len(unsigned long num)
{
	unsigned long	len;

	len = 0;
	while (num)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	hexdec(unsigned long num, char *hexstr)
{
	char	*hex_char;

	hex_char = "0123456789abcdef";
	while (num > 0)
	{
		*hexstr = hex_char[num % 16];
		num = num / 16;
		hexstr++;
	}
	*hexstr = '\0';
}

int	ft_putptr(unsigned long num, int *c_count)
{
	char			*hexstr;
	unsigned long	len;

	if (write(1, "0x", 2) == -1)
		return ((*c_count) = -1);
	*c_count += 2;
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return ((*c_count) = -1);
		(*c_count)++;
	}
	len = get_len(num);
	hexstr = malloc(len + 3);
	if (hexstr == NULL)
		return ((*c_count) = -1);
	hexdec(num, hexstr);
	while (len-- > 0 && *c_count != -1)
		ft_putchr(hexstr[len], c_count);
	free(hexstr);
	return (*c_count);
}
