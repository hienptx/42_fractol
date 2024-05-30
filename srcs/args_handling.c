/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:42:53 by hipham            #+#    #+#             */
/*   Updated: 2024/05/30 17:26:58 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	valid_double(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		while (*str != '\0' && ft_isspace(*str))
			str++;
		if (*str != '\0' && (*str == '-' || *str == '+'))
			str++;
		if (*str == '\0' || !ft_isdigit(*str))
			return (1);
		while (*str != '\0' && ft_isdigit(*str))
			str++;
		if (*str != '\0' && *str == '.')
		{
			str++;
			if (*str == '\0')
				return (1);
		}
		while (*str != '\0' && ft_isdigit(*str))
			str++;
		if (*str != '\0' && !ft_isdigit(*str))
			return (1);
	}
	return (0);
}

void	args_handling(t_fractol *ft, int ac, char **av)
{
	ft->name = av[1];
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		ft->set = 1;
	else if (ac == 2 && ft_strcmp(av[1], "julia") == 0)
		ft->set = 2;
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		if (valid_double(av[2]) == 1 || valid_double(av[3]) == 1)
			ft->set = -1;
		else
			ft->set = 3;
		ft->julia.cr = ft_atof(av[2]);
		ft->julia.ci = ft_atof(av[3]);
	}
	else if (ac == 2 && ft_strcmp(av[1], "burningship") == 0)
		ft->set = 4;
}
