/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:37:34 by hipham            #+#    #+#             */
/*   Updated: 2023/11/08 20:33:56 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchr(char c, int *c_count);
int	ft_putstr(char *s, int *c_count);
int	ft_putnbr(int num, int *c_count);
int	ft_putunbr(unsigned int num, int *c_count);
int	ft_puthex(unsigned int num, const char c, int *c_count);
int	ft_putptr(unsigned long num, int *c_count);

#endif
