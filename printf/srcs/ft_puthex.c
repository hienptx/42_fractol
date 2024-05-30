/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:11:31 by hipham            #+#    #+#             */
/*   Updated: 2023/11/09 16:27:30 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_len(unsigned int num)
{
	unsigned int	len;

	len = 0;
	while (num)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	hexdec(unsigned int num, const char c, char *hexstr)
{
	char	*hex_char;

	if (c == 'X')
		hex_char = "0123456789ABCDEF";
	if (c == 'x')
		hex_char = "0123456789abcdef";
	while (num > 0)
	{
		*hexstr = hex_char[num % 16];
		num = num / 16;
		hexstr++;
	}
	*hexstr = '\0';
}

int	ft_puthex(unsigned int num, const char c, int *c_count)
{
	char			*hexstr;
	unsigned int	len;

	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return ((*c_count) = -1);
		(*c_count)++;
	}
	len = get_len(num);
	hexstr = malloc(len + 1);
	if (hexstr == NULL)
		return ((*c_count) = -1);
	hexdec(num, c, hexstr);
	while (len-- > 0 && *c_count != -1)
		ft_putchr(hexstr[len], c_count);
	free(hexstr);
	return (*c_count);
}
