/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:35:28 by hipham            #+#    #+#             */
/*   Updated: 2024/05/28 14:58:37 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>

static double	to_fraction(double output, char *str, int i)
{
	double	divisor;

	divisor = 10.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		output += (str[i] - '0') / divisor;
		divisor *= 10.0;
		i++;
	}
	return (output);
}

double	ft_atof(char *str)
{
	int		i;
	int		neopo;
	double	output;

	i = 0;
	neopo = 1;
	output = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neopo = -neopo;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = (str[i] - '0') + (output * 10);
		i++;
	}
	if (str[i] == '.')
		output = to_fraction(output, str, ++i);
	return (output * neopo);
}

// int	main(void)
// {
// 	printf("%f", ft_atof("0.3a4"));
// 	return (0);
// }
