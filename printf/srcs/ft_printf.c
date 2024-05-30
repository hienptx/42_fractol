/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:09:32 by hipham            #+#    #+#             */
/*   Updated: 2023/11/09 15:43:31 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	casecheck(const char *format, va_list args, int *c_count)
{
	if (*format == 'c')
		ft_putchr(va_arg(args, int), c_count);
	else if (*format == '%')
		ft_putchr(*format, c_count);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), c_count);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), c_count);
	else if (*format == 'u')
		ft_putunbr(va_arg(args, unsigned int), c_count);
	else if (*format == 'x' || *format == 'X')
		ft_puthex(va_arg(args, unsigned int), *format, c_count);
	else if (*format == 'p')
		ft_putptr(va_arg(args, unsigned long), c_count);
	else
		ft_putchr(*(--format), c_count);
}

int	process_input(const char *format, va_list args, int *c_count)
{
	while (*format && *c_count != -1)
	{
		if (*format == '%')
		{
			format++;
			casecheck(format, args, c_count);
		}
		else
			ft_putchr(*format, c_count);
		format++;
	}
	return (*c_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	cpy_args;
	int		c_count;

	c_count = 0;
	va_start(args, format);
	va_copy(cpy_args, args);
	process_input(format, cpy_args, &c_count);
	va_end(args);
	va_end(cpy_args);
	return (c_count);
}

// int	main(void)
// {
// 	int a = 12;

// 	char *ptr;
// 	ptr = "";
// printf ("int return (1 = %d\n", ft_printf(" %% ")));
// printf ("int return (2 = %d\n", ft_printf(" %%%%%% ")));
// printf ("int return (3 = %d\n", ft_printf(" %%cc%c%c ",'A', 'B')));
// ft_printf ("int return (4 = %d\n\n", ft_printf("n\023\r\\nk\n")));
// 	printf ("int return 5 = %d\n", ft_printf ("output str = %s",
// "print me\n"));
// 	printf ("int return 6 = %d\n", ft_printf ("output str1 = %ss%%",
// "unpri\tntable \0\n"));
// 	printf ("int return 7 = %d\n", ft_printf ("print nbr = %d, %d, %d\n", 0,
// -2147483648, -1009));
// printf ("int return (8 = %d\n", ft_printf("%uuuu ", 4294967295)));
// printf ("int return (9 = %d\n", ft_printf("%u ", 56)));
// printf ("int return (10 = %d\n", ft_printf("%u ", -100)));
// printf ("int return (11 = %d\n\n", ft_printf("%u ", -429496729)));
// printf ("int return (13 = %d\n", ft_printf("%x ", 118571)));
// printf ("int return (14 = %d\n", ft_printf("%x ", 600)));
// ft_printf ("int return (14 = %d\n", ft_printf("%x ", 0)));
// printf ("int return (14 = %d\n", ft_printf("%x ", 2147483647)));
// ft_printf ("int return (14 = %d\n", ft_printf("%x %x %x %x %x ", -1, 1, 9,
// 10, 100)));
// printf ("int return (14 = %d\n\n", ft_printf("%X ", 2147483647)));
// printf ("int return (12 = %d\n", ft_printf("%p ", &a)));
// printf ("int return (12 = %d\n", ft_printf("%p ", ptr)));

// 	printf("write return (value = %li\n", write(1, "(null)\n", 6)));
// printf ("int return (1 = %d\n", printf(" %% ")));
// printf ("int return (2 = %d\n", printf(" %%%%%% ")));
// printf ("int return (3 = %d\n", printf(" %%cc%c%c ", 'A', 'B')));
// printf ("int return (4 = %d\n", printf("n\023\r\\nk\n")));
// 	printf ("int return (5 = %d\n", printf ("output str = %s",
// "print me\n")));
// 	printf ("int return 6 = %d\n", printf ("output str1 = %ss%%",
// "unpri\tntable \0\n"));
// 	printf ("int return (7 = %d\n", printf ("print nbr = %d, %ld, %d\n", 0,
// -2147483648, -1009));
// 	printf ("int return (8 = %d\n", printf("%lduuu ", 4294967295)));
// 	printf ("int return (9 = %d\n", printf("%u ", 56)));
// 	printf ("int return (10 = %d\n", printf("%u ", -100)));
// 	printf ("int return (11 = %d\n", printf("%u ", -429496729)));
// 	printf ("int return (13 = %d\n", printf("%x ", 118571)));
// 	printf ("int return (14 = %d\n", printf("%x ", 600)));
// 	printf ("int return (14 = %d\n", printf("%x ", 0)));
// printf ("int return (14 = %d\n", printf("%x ", 2147483647)));
// printf ("int return 14 = %d\n", printf("%x %x %x %x %x ", -1, 1, 9, 10,
// 100));
// printf ("int return (14 = %d\n\n", printf("%X ", 2147483647)));
// 	printf ("int return (12 = %d\n", printf("%p ", &a)));
// 	printf ("int return (12 = %d\n", printf("%p ", ptr)));
// }